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

  String payload = "{\"air_quality\":" + String(value) + "}";

  client.publish(TOPIC_MQ135, payload.c_str());
}
