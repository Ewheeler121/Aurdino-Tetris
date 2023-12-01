#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <Arduino.h>
#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

namespace Color {
    const static uint16_t BLACK = (0 << 11) | (0 << 6) | (0 << 1);
    const static uint16_t RED = (7 << 11) | (0 << 6) | (0 << 1);
    const static uint16_t ORANGE = (7 << 11) | (3 << 6) | (0 << 1);
    const static uint16_t YELLOW = (7 << 11) | (7 << 6) | (0 << 1);
    const static uint16_t GREEN = (0 << 11) | (7 << 6) | (0 << 1);
    const static uint16_t BLUE = (0 << 11) | (0 << 6) | (7 << 1);
    const static uint16_t PURPLE = (7 << 11) | (0 << 6) | (7 << 1);
    const static uint16_t WHITE = (7 << 11) | (7 << 6) | (7 << 1);
    const static uint16_t LIME = (3 << 11) | (7 << 6) | (0 << 1);
    const static uint16_t AQUA = (0 << 11) | (7 << 6) | (7 << 1);
}

class Screen {
    private:
        const uint8_t CLK  = 8;
        const uint8_t LAT = A3;
        const uint8_t OE = 9;
        const uint8_t A = A0;
        const uint8_t B = A1;
        const uint8_t C = A2;

        RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
    
    public:
        Screen();
        static Screen& getInstance();
        void drawPixel(uint16_t x, uint16_t y, uint16_t color);
};

#endif
