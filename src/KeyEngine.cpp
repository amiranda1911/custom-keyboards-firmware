#include "KeyEngine.hpp"


volatile bool encoderMoved = false; // Flag encoder moved
volatile int encoderDirection = 0;  // +1 or -1

static int lastEncoded = 0;
static volatile int encPosition = 0;

static void readEncoder() {
    int MSB = digitalRead(encoder_pins[0]); // Pino A
    int LSB = digitalRead(encoder_pins[1]); // Pino B

    int encoded = (MSB << 1) | LSB;
    int sum = (lastEncoded << 2) | encoded;

    if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
        encoderDirection = +1;
        encoderMoved = true;
    } 
    else if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
        encoderDirection = -1;
        encoderMoved = true;
    }

    lastEncoded = encoded;
}


KeyEngine::KeyEngine() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1)
{

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { //I2C address
        Serial.println(F("SSD1306 allocation failed"));
    }

    
    
    pinMode(encoder_pins[0],INPUT);
    pinMode(encoder_pins[1],INPUT);

    attachInterrupt(digitalPinToInterrupt(encoder_pins[0]), readEncoder, CHANGE);
    attachInterrupt(digitalPinToInterrupt(encoder_pins[1]), readEncoder, CHANGE);
    
    BootKeyboard.begin();
    Consumer.begin();
    
    delay(1000);

}

void KeyEngine::update(){
    matrixKeys();
    updateDisplay();

    if (encoderMoved) {
        encoderMoved = false; // clear flag
        encPosition += encoderDirection;

        if (encoderDirection > 0) {

            Consumer.write(ENCODER_A);
        }
        if (encoderDirection < 0)
        {
            Consumer.write(ENCODER_B);
        }
    }
}

void KeyEngine::matrixKeys()
{
    #ifdef COLS2ROWS
    for(byte r=0; r < keyRowsCount; r++ ){
        pinMode(pinRows[r], INPUT_PULLUP);
    }
     for(byte c=0; c < keyColsCount; c++ ){
        pinMode(pinCols[c], OUTPUT);
        digitalWrite(pinCols[c], HIGH);
    }

    for (byte c = 0; c < keyColsCount; c++) {
        // Activate line
        digitalWrite(pinCols[c], LOW);

        for (byte r = 0; r < keyRowsCount; r++) {

            bool pressed = !digitalRead(pinRows[r]); //read row pin (active in low)

            if (pressed && !keyState[r][c]) {
                keyPress(r,c);
                keyState[r][c] = true;
            } else if (!pressed && keyState[r][c]) {
                keyRelease(r,c);
                keyState[r][c] = false;
            }
        }
    }
    #endif


}

void KeyEngine::keyPress(byte col, byte row){
    if(keyConfig[curLayer][row][col] == KEY_LAYER_UP && !keyState[row][col])
        curLayer ++;
    if(keyConfig[curLayer][row][col] == KEY_LAYER_DOWN && !keyState[row][col])
        curLayer --;

    BootKeyboard.press(keyConfig[curLayer][row][col]);
    
}

void KeyEngine::keyRelease(byte col, byte row){
    if(keyConfig[curLayer][row][col] == KEY_LAYER_UP && keyState[row][col])
        curLayer = 1;
    if(keyConfig[curLayer][row][col] == KEY_LAYER_DOWN && keyState[row][col])
        curLayer = 1;

    BootKeyboard.release(keyConfig[curLayer][row][col]);
}

void KeyEngine::updateDisplay(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,10);
    display.print(encPosition);
    display.setCursor(25,10);
    display.print(lastEncoded);
    display.display();
}
