#pragma once

#include <PubSubClient.h>

void mqtt_setup(const char* server, uint16_t port, const char* username, const char* password);
void mqtt_reconnect();

// Publish a single sensor reading to iot/{env}/{deviceId}/{sensorType}
// Topic structure and payload are built internally.
void mqtt_publish_sensor(const char* sensorType, float value, const char* unit);

// Global client instance shared with sensor modules
extern PubSubClient client;

// Unique device identifier derived from ESP32 eFuse MAC (computed once in mqtt_setup)
extern char DEVICE_ID[13];
