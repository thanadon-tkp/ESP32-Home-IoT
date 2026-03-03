#include "dht_sensor.h"
#include "mqtt_manager.h"
#include "config.h"
#include "DHT.h"
#include <Arduino.h>

static DHT dht(DHTPIN, DHTTYPE);

void dht_init()
{
  dht.begin();
}

void dht_read()
{
  float humidity    = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature))
  {
    return;
  }

  mqtt_publish_sensor("temperature", temperature, "C");
  mqtt_publish_sensor("humidity",    humidity,    "%");
}
