#include "HX711_light.h"

constexpr uint8_t kClockPin = 4;  // Pin connected to HX711 PD_SCK.
constexpr uint8_t kDataPin = 5;   // Pin connected to HX7111 DOUT.

const int print_interval = 20;
unsigned long last_print_time = 0;

HX711_light HX711(kDataPin, kClockPin);

void setup() {
  HX711.begin();
  // Available settings: CH_A_128 (default), CH_A_64, CH_B_32
  HX711.setChannelAndGain(HX711_light::CH_A_128);
  Serial.begin(115200);
}

void loop() {
  // Run update() at high frequency with other cooperatively multitasking update functions.
  // update() will never block.
  HX711.update();
  // Since update does not block, we need to moderate the print frequency.
  if (millis() - last_print_time >= print_interval) {
    last_print_time += print_interval;
    // data() will always return the latest reading.
    Serial.println(HX711.data());
  }
}
