#ifndef _HX711_LIGHT_H
#define _HX711_LIGHT_H

class HX711_light {
public:
  // Channel and gain settings.
  enum Settings {
    CH_A_128 = 0,
    CH_A_64,
    CH_B_32
  };
  HX711_light(uint8_t dat_pin, uint8_t clk_pin);
  void begin();
  bool dataReady();
  int32_t readData();
  int32_t data();
  void HX711_light::update();
  void setChannelAndGain(Settings settings);

private:
  uint8_t dat_pin_ = 0;
  uint8_t clk_pin_ = 0;
  int32_t data_ = 0;
  Settings settings_ = 0;
};

#endif  // _HX711_LIGHT_H
