#include "Controller.hpp"

Controller::Controller() {
    for(int i = 0; i < LIMIT; i++) {
        pinMode(BUTTONS_PIN_NUMBER + i, INPUT);
    }
}

Controller& Controller::getInstance() {
    static Controller instance;
    return instance;
}

bool Controller::buttonPressed(Button button) {
    return buttonCurrentState[button] && !buttonPreviousState[button];
}

bool Controller::buttonHold(Button button) {
    return buttonCurrentState[button] && buttonPreviousState[button];
}

bool Controller::buttonRelease(Button button) {
    return !buttonCurrentState[button] && buttonPreviousState[button];
}

void Controller::update() {
    memcpy(buttonPreviousState, buttonCurrentState, sizeof(bool) * LIMIT);

    potentiometerValue = analogRead(POTENTIOMETER_PIN);
    for(int i = 0; i < LIMIT; i++) {
        buttonCurrentState[i] = digitalRead(BUTTONS_PIN_NUMBER + i == HIGH);
    }
}
