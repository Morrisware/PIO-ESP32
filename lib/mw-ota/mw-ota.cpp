#include <ArduinoOTA.h>

void setup_OTA(const char* host) {
  ArduinoOTA.setHostname(host);
  ArduinoOTA.setMdnsEnabled(true);
  ArduinoOTA.begin();
}