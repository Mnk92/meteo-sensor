#include "th_sensor.h"

namespace meteo {

THSensor::THSensor(Logger& logger)
    : logger(logger), ath10(AHT10_ADDRESS_0X38) {}
bool THSensor::init() { return ath10.begin(); }

THData THSensor::read() {
  if (auto readStatus = ath10.readRawData(); readStatus != AHT10_ERROR) {
    return {ath10.readTemperature(AHT10_USE_READ_DATA),
            ath10.readHumidity(AHT10_USE_READ_DATA)};
  }
  return {0, 0};
}
}  // namespace meteo