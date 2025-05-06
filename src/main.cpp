#include "KeyEngine.hpp"

int main ()
{
  init(); // inicializa o Arduino core (timers, ADC, etc.)
  KeyEngine * keyboard = new KeyEngine();
    
  // the loop function runs over and over again forever
  while(true) {
    keyboard->update();
    delay(10);
  }
}