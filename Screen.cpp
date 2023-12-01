#include "Screen.hpp"

Screen::Screen() {
    matrix.begin();
}

Screen& Screen::getInstance() {
    static Screen instance;
    return instance;
}

void Screen::drawPixel(uint16_t x, uint16_t y, uint16_t color) {
    matrix.drawPixel(y, x, color);
}
