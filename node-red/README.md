# Node-RED Fog Layer

Node-RED is used as the fog processing layer in the IoT-Fog-Cloud architecture.

## Role

The Node-RED flow receives temperature data from the ESP8266 through MQTT and performs fog-level processing.

## Processing Flow
```
ESP8266
↓
MQTT Topic: `esp8266/data`
↓
Mosquitto MQTT Broker
↓
Node-RED
↓
Threshold Processing
↓
Alert Generation / Dashboard
↓
InfluxDB
```
## Main Functions

- Receive temperature data through MQTT
- Process incoming sensor data
- Apply temperature threshold logic
- Generate alerts
- Control fog-level processing
- Forward processed data to InfluxDB
- Display data through the Node-RED dashboard

## MQTT Input

**Topic:** `esp8266/data`

**Broker:** Mosquitto MQTT Broker

## Flow File

The Node-RED flow configuration is available in:

`flows.json`

## Importing the Flow

1. Open Node-RED.
2. Select the menu.
3. Choose **Import**.
4. Select `flows.json`.
5. Import the flow.
6. Configure the MQTT broker and other local settings.
7. Deploy the flow.

> Configuration values such as broker addresses and credentials may need to be changed for another environment.
