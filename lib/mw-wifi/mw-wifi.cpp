#include "Wifi.h"
#include <WiFiType.h>

void wifi_connect_sta(const char* wifi_ssid, const char* wifi_password)
{
  WiFi.begin(wifi_ssid, wifi_password);
  uint32_t notConnectedCounter = 0;
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.println("Wifi connecting...");
      notConnectedCounter++;
      if(notConnectedCounter > 150) { // Reset board if not connected after 5s
          Serial.println("Resetting due to Wifi not connecting...");
          ESP.restart();
      }
  }
  Serial.print("Wifi connected, IP address: ");
  Serial.println(WiFi.localIP());
}
