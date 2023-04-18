#include "HX711_light.h"

constexpr uint8_t kClockPin = 4;  // Pin connected to HX711 PD_SCK.
constexpr uint8_t kDataPin = 5;   // Pin connected to HX7111 DOUT.

HX711_light HX711(kDataPin, kClockPin);

void setup() {
  HX711.begin();
  // Available settings: CH_A_128 (default), CH_A_64, CH_B_32
  HX711.setChannelAndGain(HX711_light::CH_A_128);
  Serial.begin(115200);
}

void loop() {
  // Read data and print over Serial.
  // getData() will block until data is available.
  long hx_data = HX711.readData();
  Serial.println(hx_data);
}
