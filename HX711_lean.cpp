#include "HX711_lean.h"

HX711_lean::HX711_lean(uint8_t dat_pin, uint8_t clk_pin) {
  dat_pin_ = dat_pin;
  clk_pin_ = clk_pin;
  settings_ = CH_A_128;
}

void HX711_lean::begin() {
  pinMode(dat_pin_, INPUT);   // Data is input to the Arduino.
  pinMode(clk_pin_, OUTPUT);  // Clock is output from the Arduino.
  digitalWrite(clk_pin_, LOW);
}

int32_t HX711_lean::getData() {
  while (digitalRead(dat_pin_)) {};
  int32_t result = 0;
  for (int i = 23; i >= 0; --i) {
    digitalWrite(clk_pin_, HIGH);
    result |= static_cast<int32_t>(digitalRead(dat_pin_)) << i;
    digitalWrite(clk_pin_, LOW);
  }
  uint8_t num_extra_cycles = 0;
  switch (settings_) {
    case CH_A_128:
      num_extra_cycles = 1;
      break;
    case CH_A_64:
      num_extra_cycles = 3;
      break;
    case CH_B_32:
      num_extra_cycles = 2;
      break;
    default:
      Serial.println("Error: Invalid settings.");
      return -1;
  }
  for (int i = 0; i < num_extra_cycles; ++i) {
    digitalWrite(clk_pin_, HIGH);
    digitalWrite(clk_pin_, LOW);
  }
  result |= (result & 1UL << 23 ? 0xFFUL : 0x00UL) << 24;
  return result;
}

void HX711_lean::setChannelAndGain(Settings settings) {
  settings_ = settings;
  getData();
}


