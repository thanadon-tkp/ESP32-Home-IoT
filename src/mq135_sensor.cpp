#include "mq135_sensor.h"
#include "mqtt_manager.h"
#include "config.h"
#include <Arduino.h>

void mq135_init()
{
  pinMode(MQ135_AO, INPUT);
}

void mq135_read()
{
  int value = analogRead(MQ135_AO);

  mqtt_publish_sensor("air_quality", value, "raw");
}
