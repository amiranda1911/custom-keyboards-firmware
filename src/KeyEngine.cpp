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

   
    updateDisplay();
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
