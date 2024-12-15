#include "shift_register.h"

// Constructor: Initializes pin numbers
ShiftRegister::ShiftRegister(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin) {
  this->dataPin = dataPin;
  this->clockPin = clockPin;
  this->latchPin = latchPin;
}

// Setup method: Configures the pins as outputs
void ShiftRegister::setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  clear();
}

// Shift in a bit (0 or 1) and latch the data
void ShiftRegister::shiftIn(bool bit) {
  digitalWrite(latchPin, LOW);  // Disable latch to prepare for data shifting
  digitalWrite(clockPin, LOW);  // Ensure clock starts low

  // Write the bit to the data pin
  digitalWrite(dataPin, bit);

  // Pulse the clock pin to shift the bit in
  digitalWrite(clockPin, HIGH);  // Clock high to shift in the bit
  digitalWrite(clockPin, LOW);   // Clock low again to prepare for the next bit

  // Latch the data after shifting
  digitalWrite(latchPin, HIGH);  // Latch data into the output register
  digitalWrite(latchPin, LOW);   // Prepare for the next cycle
}

// clear all output to zero
void ShiftRegister::clear(){
  for(int i=0; i<8;i++){
    shiftIn(0);
  }
}
