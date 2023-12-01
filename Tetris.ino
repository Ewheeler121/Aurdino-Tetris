#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;

const int POTENTIOMETER_PIN = 5;
const int BUTTONS_PIN_NUMBER = 10;

const long interval = 1000/60;
unsigned long prevMills;

namespace Device {
  namespace Screen {
    RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

    void setup() {
      matrix.begin();
    }

    bool drawPixel(uint16_t x, uint16_t y, uint16_t color) {
      matrix.drawPixel(y, x, color);
    }

  }

  namespace Color {
    const uint16_t BLACK = Screen::matrix.Color333(0, 0, 0);
    const uint16_t RED = Screen::matrix.Color333(4, 0, 0);
    const uint16_t ORANGE = Screen::matrix.Color333(6, 1, 0);
    const uint16_t YELLOW = Screen::matrix.Color333(4, 4, 0);
    const uint16_t GREEN = Screen::matrix.Color333(0, 4, 0);
    const uint16_t BLUE = Screen::matrix.Color333(0, 0, 4);
    const uint16_t PURPLE = Screen::matrix.Color333(1, 0, 2);
    const uint16_t WHITE = Screen::matrix.Color333(4, 4, 4);
    const uint16_t LIME = Screen::matrix.Color333(2, 4, 0);
    const uint16_t AQUA = Screen::matrix.Color333(0, 4, 4);
  }

  namespace Controller {
    enum Button {
      ROTATE_LEFT,
      ROTATE_RIGHT,
      QUICK_DROP,
      HOLD,
      LIMIT
    };

    int potentiometer_value = 0;

    bool button_previous_state[LIMIT];
    bool button_state[LIMIT];

    void setup() {
      pinMode(BUTTONS_PIN_NUMBER, INPUT);
    }

    bool pressed(Button b) {
      return button_state[b] && !button_previous_state[b];
    }

    bool hold(Button b) {
      return button_state[b] && button_previous_state[b];
    }

    bool release(Button b) {
      return !button_state[b] && button_previous_state[b];
    }

    void update() {
      memcpy(button_previous_state, button_state, sizeof(bool) * LIMIT);

      potentiometer_value = analogRead(POTENTIOMETER_PIN);
      for(int i = 0; i < LIMIT; i++) {
        button_state[i] = (digitalRead(BUTTONS_PIN_NUMBER + i) == HIGH);
      }
    }
  }

  void setup() {
    Serial.begin(9600);
    prevMills = 0;
    Controller::setup();
    Screen::setup();
  }
}

void setup() {
  Device::setup();
}

void loop() {
  using namespace Device;

  unsigned long currentMills = millis();

  if(currentMills - prevMills >= interval) {
    prevMills = currentMills;
    Controller::update();
    //tick
  }
  //render
}
