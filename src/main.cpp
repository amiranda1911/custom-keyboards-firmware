#include "core.hpp"

int main ()
{
  init(); // inicializa o Arduino core (timers, ADC, etc.)
  Keyboard.begin();
    
  // the loop function runs over and over again forever
  while(true) {
    Keyboard.write((uint8_t)'A');
    Serial.println("Loop");
    delay(500);                 // wait for a second
  }
}