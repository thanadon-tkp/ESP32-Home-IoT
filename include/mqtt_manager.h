#pragma once

#include <PubSubClient.h>

void mqtt_setup(const char* server, uint16_t port);
void mqtt_reconnect();

// Global client instance shared with sensor modules
extern PubSubClient client;
