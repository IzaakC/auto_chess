#include <FastLED.h>
#include "shift_register.h"

#define LED_PIN 7
#define NUM_LEDS 64

CRGB leds[NUM_LEDS];
ShiftRegister shiftRegister = ShiftRegister(10,11,12);

// uint8_t led_board[8][8] = {
//   { 100, 0, 0, 0, 0, 0, 0, 255 },  // Top row with corners 255
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 0, 0, 0, 0, 0, 0, 0, 0 },
//   { 255, 0, 0, 0, 0, 0, 0, 255 }  // Bottom row with corners 255
// };
// ;


// void led_setup() {
//   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
//   for (int i = 0; i < NUM_LEDS; i++) {
//     leds[i] = CRGB(0, 0, 0);
//   }
// }


// void write_led_board() {
//   for (int row = 0; row < 8; row++) {
//     for (int col = 0; col < 8; col++) {
//       uint8_t value = led_board[row][col];
//       leds[col + row * 8] = CRGB(value, 0, 0);
//     }
//   }
//   FastLED.show();
// }

void setup() {
  shiftRegister.setup();
  // led_setup();
  // write_led_board();
}

void loop() {
  shiftRegister.shiftIn(1);
  delay(1000);
  for(int i=0; i<8;i++){
    shiftRegister.shiftIn(0);
    delay(1000);
  }
}