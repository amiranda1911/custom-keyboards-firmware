#pragma once
#include "Core.hpp"
#include "Keymap.hpp"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

static int lastEncoded = 0;
static volatile int encPosition = 0;


static void readEncoder();

class KeyEngine
{

private:
    Keymap* keymap;
    Adafruit_SSD1306 display;

public:
    KeyEngine();
    
    void updateDisplay();
    

};
