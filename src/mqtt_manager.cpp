#include "mqtt_manager.h"
#include "config.h"
#include <WiFi.h>
#include <Arduino.h>
#include <ArduinoJson.h>

WiFiClient espClient;
PubSubClient client(espClient);

char DEVICE_ID[13]; // 12 hex chars + null terminator

const char *user;
const char *pass;

void mqtt_setup(const char *server, uint16_t port, const char *username, const char *password)
{
  // Derive device ID from eFuse MAC once at startup
  uint64_t chipid = ESP.getEfuseMac();
  snprintf(DEVICE_ID, sizeof(DEVICE_ID), "%04X%08X",
           (uint16_t)(chipid >> 32),
           (uint32_t)chipid);
  Serial.printf("DeviceId: %s\n", DEVICE_ID);

  client.setServer(server, port);
  user = username;
  pass = password;
}

void mqtt_publish_sensor(const char* sensorType, float value, const char* unit)
{
  // Topic: iot/{env}/{deviceId}/{sensorType}
  char topic[128];
  snprintf(topic, sizeof(topic), "iot/%s/%s/%s", MQTT_ENV, DEVICE_ID, sensorType);

  // Payload: {"value": X, "unit": "Y"}
  JsonDocument doc;
  doc["value"] = value;
  doc["unit"]  = unit;

  char payload[64];
  serializeJson(doc, payload);

  client.publish(topic, payload);
}

void mqtt_reconnect()
{
  while (!client.connected())
  {
    Serial.println("Connecting MQTT...");
    if (client.connect(DEVICE_ID, user, pass))
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
