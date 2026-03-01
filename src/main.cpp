#include <Arduino.h>
#include "config.h"
#include "wifi_manager.h"
#include "mqtt_manager.h"
#include "dht_sensor.h"
#include "mq135_sensor.h"

// Timing control (non-blocking delays)
unsigned long lastDHTRead    = 0;
unsigned long lastMQ135AORead = 0;

void setup()
{
  Serial.begin(115200);
  wifi_setup(WIFI_SSID, WIFI_PASSWORD);
  mqtt_setup(MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);
  dht_init();
  mq135_init();
}

void loop()
{
  if (!client.connected())
  {
    mqtt_reconnect();
  }
  client.loop();

  unsigned long currentMillis = millis();

  // DHT every 2 seconds
  if (currentMillis - lastDHTRead >= DHT_INTERVAL)
  {
    lastDHTRead = currentMillis;
    dht_read();
  }

  // MQ135 AO every 0.5 second
  if (currentMillis - lastMQ135AORead >= MQ135_AO_INTERVAL)
  {
    lastMQ135AORead = currentMillis;
    mq135_read();
  }
}