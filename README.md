# Arduino Tetris Game Using Adafruit 16x32 Screen and Breadboard Controller

This document describes the setup and programming of a Tetris game using an Arduino microcontroller, an Adafruit 16x32 LED matrix screen, and a custom breadboard controller.

## Components

1. Arduino Uno (or compatible microcontroller)
2. Adafruit 16x32 RGB LED matrix panel
3. Breadboard
4. Pushbuttons (4)
5. Jumper wires
6. Resistor 10k Ohm (4, for pull-down resistors)

## Circuit Diagram

The circuit involves connecting the four pushbuttons to the Arduino for controlling the Tetris game. The buttons are used for moving left, moving right, rotating the Tetrimino, and speeding up the drop.


## Arduino Setup

- Connect the Adafruit 16x32 screen to the Arduino as per Adafruit's documentation.
- Connect each button to a digital input pin on the Arduino. Use 10k Ohm resistors as pull-down resistors for each button.
- Connect a potentiometer to a digital input pin on the Arduino.
- Connect the common ground from the breadboard to the Arduino's ground.

## Programming

### Libraries

- Adafruit_GFX.h
- RGBmatrixPanel.h

### Key Functions

- `setup()`: Initialize the screen and button inputs.
- `loop()`: Main game loop. Handles input processing and screen updates.

### Game Logic

- The game consists of typical Tetris mechanics: creating Tetriminos, moving them, rotating them, and clearing lines.
- Button presses are translated into game actions (rotate left, rotate right, hold, quick drop).
- Potentiometer is translated to be moving left or right

### Display

- The Adafruit 16x32 screen displays the Tetris game, updating each frame to reflect the current game state.

## Example Code

```cpp
#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>
 
void setup() {
  Device::setup();
}

void loop() {
 using namespace Device;

  unsigned long currentMills = millis();

  if(currentMills - prevMills >= interval) {
    prevMills = currentMills;
    Game::tick(); //game-logic at 60 FPS
  }
  
  Screen::render(); //render to screen
}


