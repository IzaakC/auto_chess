#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

#include <Arduino.h>

class ShiftRegister {
  private:
    uint8_t dataPin;   // Pin connected to SER 14
    uint8_t latchPin;  // Pin connected to RCLK 12
    uint8_t clockPin;  // Pin connected to SRCLK 11

  public:
    // Constructor: Takes pin numbers for data, clock, and latch
    ShiftRegister(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin);

    // Setup method: Configures pin modes
    void setup();

    // Shift in a bit (0 or 1), latches after shifting
    void shiftIn(bool bit);


    // clear all output to zero
    void clear();
};

#endif
