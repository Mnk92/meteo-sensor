#include <Arduino.h>
#include <LowPower.h>
#include <avr/power.h>
#include <stdint.h>

#include "logger.h"
#include "th_sensor.h"
#include "transmitter.h"

using namespace meteo;
Logger logger;
THSensor th(logger);
Transmitter tx;

constexpr const char* boolToString(bool value) {
  return value ? "OK" : "FAILED";
}
unsigned long loopIteration{0};

void setup() {
  // clock_prescale_set(clock_div_16);
  logger.init(LogLevel::OFF);
  logger.log(LogLevel::INFO, "Init AHT10 %s", boolToString(th.init()));
  logger.log(LogLevel::INFO, "Init FS1000A %s", boolToString(tx.init()));
}

void loop() {
  if (loopIteration % 7 == 0) {
    // send data approximately once per minute.
    auto const data = th.read();
    logger.log(LogLevel::INFO, "%d %d", (int)data.temperature,
               (int)data.humidity);
    if (!tx.send(data)) {
      logger.log(LogLevel::ERROR, "Can't send data.");
    }
  }
  ++loopIteration;
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
}