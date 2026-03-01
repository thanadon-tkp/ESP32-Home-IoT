#pragma once

#include <PubSubClient.h>

void mqtt_setup(const char* server, uint16_t port, const char* username, const char* password);
void mqtt_reconnect();

// Global client instance shared with sensor modules
extern PubSubClient client;
