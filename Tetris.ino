#include "Screen.hpp"
#include "Controller.hpp"

const long interval = 1000/60;
unsigned long prevMills;

Screen* screen;
Controller* controller;

void setup() {
    Serial.begin(9600);
    
    screen = Screen.getInstance();
    controller = Controller.getInstance();
    
    prevMills = 0;
}

void loop() {
    unsigned long currentMills = millis();

    if(currentMills - prevMills >= interval) {
        prevMills = currentMills;
        controller->update();

        for(int i = 0; i < LIMIT; i++) {
            if(controller->buttonPressed(i)) {
                Serial.print(i + 1);
                Serial.println(" button pressed");
            } else if(controller->buttonHeld(i)) {
                Serial.print(i + 1);
                Serial.println(" button held");
            } else if(controller->buttonReleased(i)) {
                Serial.print(i + 1);
                Serial.println(" button released");
            }
        }
    }
    
    screen->drawPixel(0, 0, Color::RED);
}
