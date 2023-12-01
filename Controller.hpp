#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <Aurdino.h>

typedef enum {
    ROTATE_LEFT,
    ROTATE_RIGHT,
    QUICK_DROP,
    HOLD,
    LIMIT
} Button;

class Controller {
    private:
        const int POTENTIOMETER_PIN = 5;
        const int BUTTONS_PIN_NUMBER = 10;

        int potentiometerValue = 0;
        bool buttonPreviousState[LIMIT];
        bool buttonCurrentState[LIMIT];
    
    public:
        Controller();
        Controller& getInstance();
        bool buttonPressed(Button button);
        bool buttonHold(Button button);
        bool buttonRelease(Button button);
        
        void update();
};

#endif
