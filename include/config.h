#pragma once

// ─── WiFi / MQTT ───────────────────────────────────
// WIFI_SSID, WIFI_PASSWORD, MQTT_SERVER, MQTT_PORT
// are injected at compile time from credentials.ini build_flags.
// Do NOT hardcode secrets here.

// ─── DHT22 ────────────────────────────────────────
#define DHTPIN  4
#define DHTTYPE DHT22

// ─── MQ135 ────────────────────────────────────────
#define MQ135_AO 34

// ─── Timing intervals (ms) ────────────────────────
#define DHT_INTERVAL     2000UL   // 2 seconds
#define MQ135_AO_INTERVAL 500UL  // 0.5 second

// ─── MQTT Topics ──────────────────────────────────
#define TOPIC_DHT22  "esp32/sensor/dht22"
#define TOPIC_MQ135  "esp32/sensor/mq135"
