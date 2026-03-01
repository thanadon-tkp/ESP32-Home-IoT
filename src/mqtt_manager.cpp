#include "mqtt_manager.h"
#include <WiFi.h>
#include <Arduino.h>

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_setup(const char* server, uint16_t port)
{
  client.setServer(server, port);
}

void mqtt_reconnect()
{
  while (!client.connected())
  {
    Serial.println("Connecting MQTT...");
    if (client.connect("ESP32Client"))
    {
      Serial.println("MQTT connected");
    }
    else
    {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" retry in 2s");
      delay(2000);
    }
  }
}
