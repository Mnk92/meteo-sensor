#include "logger.h"
namespace meteo {
void Logger::init(LogLevel level) {
  max_level = level;
  if (level != LogLevel::OFF) {
    Serial.begin(9600);
  }
}

const char* Logger::levelToString(LogLevel level) {
  switch (level) {
    case LogLevel::ERROR:
      return "Error";
    case LogLevel::WARNING:
      return "Warning";
    case LogLevel::INFO:
      return "Info";
    case LogLevel::DEBUG:
      return "Debug";
  };
  return "(unknown)";
}

}  // namespace meteo