#include "transmitter.h"

namespace meteo {
Transmitter::Transmitter() : driver(2000, 3, 2 /*tx pin*/) {}
bool Transmitter::init() { return driver.init(); }
bool Transmitter::send(const uint8_t* data, uint8_t size) {
  if (driver.send(data, size)) {
    return driver.waitPacketSent();
  }
  return false;
}
}  // namespace meteo