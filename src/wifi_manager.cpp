#include "wifi_manager.h"
#include <WiFi.h>
#include <Arduino.h>

void wifi_setup(const char* ssid, const char* password)
{
  delay(10);
  Serial.println("Connecting WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}
