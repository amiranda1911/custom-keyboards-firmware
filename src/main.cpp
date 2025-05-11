#include "KeyEngine.hpp"

 KeyEngine * keyboard;


void setup ()
{
  // inicializa o Arduino core (timers, ADC, etc.)
    keyboard = new KeyEngine();
    delay(1000);

}

void loop()
{
  keyboard->update();
  delay(10);

}