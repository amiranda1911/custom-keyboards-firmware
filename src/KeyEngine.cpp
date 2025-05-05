#include "KeyEngine.hpp"

static void readEncoder() {
    int MSB = digitalRead(encoder_pins[0]); // Pino A (MSB)
    int LSB = digitalRead(encoder_pins[1]); // Pino B (LSB)
    
    int encoded = (MSB << 1) | LSB; // Combina os dois bits
    int sum = (lastEncoded << 2) | encoded; // Adiciona ao histórico
    
    if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
        encPosition++;
    } else if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
        encPosition--;
    }
    
    lastEncoded = encoded; // Atualiza o histórico
}


KeyEngine::KeyEngine() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1)
{

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Endereço I2C
        Serial.println(F("SSD1306 allocation failed"));
    }

    display.clearDisplay();
    pinMode(encoder_pins[0],INPUT);
    pinMode(encoder_pins[1],INPUT);

    attachInterrupt(digitalPinToInterrupt(encoder_pins[0]), readEncoder, CHANGE);
    attachInterrupt(digitalPinToInterrupt(encoder_pins[1]), readEncoder, CHANGE);

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