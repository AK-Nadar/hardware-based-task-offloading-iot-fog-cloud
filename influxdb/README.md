# InfluxDB Cloud Storage Layer

InfluxDB is used as the time-series database in the cloud layer of the IoT-Fog-Cloud architecture.

## Role

The system stores temperature measurements and latency-related data in InfluxDB for historical analysis and visualization.

## Configuration

- InfluxDB Version: 1.x
- Host: `localhost`
- Port: `8086`
- Database: `iot_temperature_shree`
- Measurement: `temperature`

## Data Flow
```
ESP8266
↓
MQTT Topic: esp8266/data
↓
Mosquitto MQTT Broker
↓
Node-RED
↓
InfluxDB
↓
Grafana
```
## Stored Data

The Node-RED flow prepares the following values for storage:

- Temperature
- Fog latency
- Cloud latency

## Measurement

The main measurement used by the project is:

`temperature`

## Purpose

InfluxDB provides time-series data storage for:

- Temperature monitoring
- Historical data analysis
- Fog and cloud latency comparison
- Grafana visualization

## Local Setup

The project uses a local InfluxDB instance running on:

`http://localhost:8086`

The database used by the project is:

`iot_temperature_shree`

> Configuration may need to be modified when running the project in another environment.
