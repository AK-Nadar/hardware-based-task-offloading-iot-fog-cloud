# MQTT Communication

MQTT is used as the communication protocol between the ESP8266 IoT device
and the fog processing layer.

## MQTT Architecture

```
ESP8266
   │
   │ Publish
   ▼
MQTT Topic: esp8266/data
   │
   ▼
Mosquitto MQTT Broker
   │
   │ Subscribe
   ▼
Node-RED
```

## MQTT Broker

Broker: Mosquitto

Host: localhost
Port: 1883

## Topic

*esp8266/data*

## Message Format

```json
{
  "temp": 28.4,
  "time": 123456789
}
