#include "KeyEngine.hpp"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R1);

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


KeyEngine::KeyEngine()
{

    u8g2.begin();
    
    pinMode(encoder_pins[0],INPUT);
    pinMode(encoder_pins[1],INPUT);

    attachInterrupt(digitalPinToInterrupt(encoder_pins[0]), readEncoder, CHANGE);
    attachInterrupt(digitalPinToInterrupt(encoder_pins[1]), readEncoder, CHANGE);
    #if defined(ARDUINO_ARCH_STM32)
    Keyboard.begin();
    #elif defined(__AVR__)
    BootKeyboard.begin();
    Consumer.begin();
    #endif


    
    for(byte r=0; r < keyRowsCount; r++ ){
        pinMode(ledRows[r], OUTPUT);
    }
    for(byte c=0; c < keyColsCount; c++ ){
        pinMode(ledCols[c], OUTPUT);
    }
    delay(1000);

}

void KeyEngine::update(){
    matrixKeys();
    updateDisplay();
    

    if (encoderMoved) {
        encoderMoved = false; // clear flag
        encPosition += encoderDirection;

        if (encoderDirection > 0) {
            #if defined(__AVR__)
            Consumer.write(ENCODER_A);
            #endif
        }
        if (encoderDirection < 0)
        {
            #if defined(__AVR__)
            Consumer.write(ENCODER_B);
            #endif
        }
    }

    for(byte c=0; c < keyColsCount; c++ ){
        
        for(byte r=0; r < keyRowsCount; r++ ){
            if(keyConfig[curLayer][r][c] != 0x00){
                digitalWrite(ledCols[c], LOW);
                digitalWrite(ledRows[r], HIGH);
                delayMicroseconds(50);
                digitalWrite(ledCols[c], HIGH);
                digitalWrite(ledRows[r], LOW);
            }
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
                keyPress(c,r);
                keyState[c][r] = true;
            } else if (!pressed && keyState[r][c]) {
                keyRelease(c,r);
                keyState[c][r] = false;
            }
        }
        digitalWrite(pinCols[c], HIGH);

    }
    #else

    for(byte c=0; c < keyColsCount; c++ ){
        pinMode(pinCols[c], INPUT_PULLUP);
    }
     for(byte r=0; r < keyRowsCount; r++ ){
        pinMode(pinRows[r], OUTPUT);
        digitalWrite(pinRows[r], HIGH);
    }

    for (byte r = 0; r < keyRowsCount; r++) {
        // Activate line
        digitalWrite(pinRows[r], LOW);
        for (byte c = 0; c < keyColsCount; c++) {
            bool pressed = !digitalRead(pinCols[c]); //read row pin (active in low)

            if (pressed && !keyState[r][c]) {
                keyPress(c,r);
                keyState[c][r] = true;
            } else if (!pressed && keyState[c][r]) {
                keyRelease(c,r);
                keyState[c][r] = false;
            }
        }
        digitalWrite(pinRows[r], HIGH);

    }
    #endif
    


}

void KeyEngine::keyPress(byte col, byte row){
    if(keyConfig[curLayer][row][col] == KEY_LAYER_UP && !keyState[row][col])
        curLayer ++;
    if(keyConfig[curLayer][row][col] == KEY_LAYER_DOWN && !keyState[row][col])
        curLayer --;
    #if defined(ARDUINO_ARCH_STM32)
    Keyboard.press(keyConfig[curLayer][row][col]);
    #elif defined(__AVR__)
    BootKeyboard.press((KeyboardKeycode)keyConfig[curLayer][row][col]);
    #endif
}

void KeyEngine::keyRelease(byte col, byte row){
    if(keyConfig[curLayer][row][col] == KEY_LAYER_UP && keyState[row][col])
        curLayer = 1;
    if(keyConfig[curLayer][row][col] == KEY_LAYER_DOWN && keyState[row][col])
        curLayer = 1;
        
    #if defined(ARDUINO_ARCH_STM32)
    Keyboard.release(keyConfig[curLayer][row][col]);
    #elif defined(__AVR__)
    BootKeyboard.release((KeyboardKeycode) keyConfig[curLayer][row][col]);
    #endif
}

void KeyEngine::updateDisplay(){
    char layerNum[3] = "";
    sprintf(layerNum, "%d", curLayer);
    char layerMsg[9] = "Layer ";
    strcat(layerMsg, layerNum );
    u8g2.firstPage();
  
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 50, layerMsg);
    u8g2.nextPage();
}
