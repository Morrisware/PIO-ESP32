#include <Arduino.h>
#include <ArduinoOTA.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>
#include "SPIFFS.h"
#include "mw-wifi.h"
#include "mw-ota.h"
#include "mw-serial.h"
#include "wifi-credentials-bt.h"

#define LED 2
const char* host = "esp32";

void recvMsg(uint8_t *data, size_t len){
  println("Received Data...");
  String d = "";
  for(int i=0; i < len; i++){
    d += char(data[i]);
  }
  println(d);

  if (d == "ON"){
    digitalWrite(LED, HIGH);
  }
  if (d=="OFF"){
    digitalWrite(LED, LOW);
  }
}
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  wifi_connect_sta(wifi_ssid, wifi_password);
  setup_OTA(host);

  WebSerial.begin(&server);
  WebSerial.msgCallback(recvMsg);
  
  if(!SPIFFS.begin(true)){
    println("An Error has occurred while mounting SPIFFS");
    return;
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });

  server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/styles.css", "text/css");
  });

  server.begin();

  pinMode(LED, OUTPUT);
}

void loop() {
  println("YY");
  delay(2000);
  ArduinoOTA.handle();
}