#pragma once
#include "Core.hpp"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keyboard.h>


class KeyEngine
{

private:
    
    Adafruit_SSD1306 display;

public:
    KeyEngine();
    void update();
    void updateDisplay();
    

};
