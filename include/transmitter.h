#pragma once
#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

namespace meteo {
class Transmitter {
 public:
  Transmitter();
  bool init();

  template <typename T>
  bool send(T const& data) {
    return send(reinterpret_cast<const uint8_t*>(&data), sizeof(data));
  }

 private:
  RH_ASK driver;
  bool send(const uint8_t* data, uint8_t size);
};
}  // namespace meteo