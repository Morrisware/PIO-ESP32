#include <WebSerial.h>

void println(const char* text, bool web = true)  {
  Serial.println(text);
  if (web) {
    WebSerial.println(text);
  }
}

void print(const char* text, bool web = true)  {
  Serial.print(text);
  if (web) {
    WebSerial.print(text);
  }
}

void println(String text, bool web = true)  {
  Serial.println(text);
  if (web) {
    WebSerial.println(text);
  }
}

void print(String text, bool web = true)  {
  Serial.print(text);
  if (web) {
    WebSerial.print(text);
  }
}