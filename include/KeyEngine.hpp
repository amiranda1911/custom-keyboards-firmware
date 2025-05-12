#pragma once
#include "core.hpp"


#ifdef _4X6_MATRIX_
    const byte keyRowsCount = 4;
    const byte keyColsCount = 6;
#endif
#ifdef _6X6_MATRIX_
    const byte keyRowsCount = 6;
    const byte keyColsCount = 6;

#endif
//#define _5X12_MATRIX_
//#define _6X14_MATRIX_
//#define _6X18_MATRIX_

class KeyEngine
{

private:
    
    Adafruit_SSD1306 display;
    bool keyState[keyRowsCount][keyColsCount];
    byte curLayer = 1;

public:
    KeyEngine();
    void update();
    void updateDisplay();
    void matrixKeys();
    void keyPress(byte col, byte row);
    void keyRelease(byte col, byte row);
};
