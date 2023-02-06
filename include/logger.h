#pragma once
#include <Arduino.h>

namespace meteo {
enum class LogLevel : uint8_t {
  OFF = 0,
  ERROR = 1,
  WARNING = 2,
  INFO = 3,
  DEBUG = 4
};

class Logger {
 public:
  void init(LogLevel level);

  template <typename... Args>
  void log(LogLevel level, const char* message, Args&&... args) {
    if (level <= max_level) {
      Serial.print(levelToString(level));
      Serial.print(" | ");
      sprintf(buffer, message, args...);
      Serial.print(buffer);
      Serial.println();
    }
  }

 private:
  LogLevel max_level;
  char buffer[200];

  const char* levelToString(LogLevel level);
};
}  // namespace meteo