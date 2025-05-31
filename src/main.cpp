#include "KeyEngine.hpp"

 KeyEngine * keyboard;


void setup ()
{
  // inicializa o Arduino core (timers, ADC, etc.)
    keyboard = new KeyEngine();
}

void loop()
{
  keyboard->update();


}
