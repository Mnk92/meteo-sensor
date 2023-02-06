#pragma once
#include <AHT10.h>
#include <Wire.h>

#include "logger.h"

namespace meteo {
struct THData {
  float temperature;
  float humidity;
};
class THSensor {
 public:
  explicit THSensor(Logger& logger);
  bool init();
  THData read();

 private:
  Logger& logger;
  AHT10 ath10;
};
}  // namespace meteo