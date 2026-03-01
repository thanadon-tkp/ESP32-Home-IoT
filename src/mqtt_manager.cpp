#include "mqtt_manager.h"
#include <WiFi.h>
#include <Arduino.h>

WiFiClient espClient;
PubSubClient client(espClient);

const char* user;
const char* pass;

void mqtt_setup(const char* server, uint16_t port, const char* username, const char* password)
{
  client.setServer(server, port);
  user = username;
  pass = password;
}

void mqtt_reconnect()
{
  while (!client.connected())
  {
    Serial.println("Connecting MQTT...");
    if (client.connect("ESP32Client", user, pass))
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
