#include "Arduino.h"

#ifndef _HX711_LEAN_H
#define _HX711_LEAN_H

class HX711_lean {
public:
  enum Settings {
    CH_A_128 = 0,
    CH_A_64,
    CH_B_32
  };
  HX711_lean(uint8_t dat_pin, uint8_t clk_pin);
  void begin();
  int32_t getData();
  void setChannelAndGain(Settings settings);

private:
  uint8_t dat_pin_ = 0;
  uint8_t clk_pin_ = 0;
  Settings settings_ = 0;
};

#endif // _HX711_LEAN_H
