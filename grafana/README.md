# Grafana Visualization Layer

Grafana is used as the visualization layer for monitoring temperature data and comparing fog and cloud processing latency.

## Role

Grafana retrieves time-series data stored in InfluxDB and presents it through an interactive dashboard.

## Dashboard

The dashboard provides real-time and historical visualization of the IoT-Fog-Cloud system.

### Dashboard Components

- Live temperature display
- Temperature gauge
- Temperature trend graph
- Fog vs Cloud latency comparison
- Temperature level visualization
- Recent data table
- Fog latency values
- Cloud latency values

## Data Source

Grafana uses InfluxDB as the data source.
```text
ESP8266
    ↓
MQTT
    ↓
Mosquitto
    ↓
Node-RED
    ↓
InfluxDB
    ↓
Grafana
```
## Metrics Visualized

### Temperature

Real-time temperature readings obtained from the LM35 sensor connected to the ESP8266.

### Fog Latency

Processing latency associated with the fog layer.

### Cloud Latency

Processing latency associated with the cloud layer.
The dashboard allows the latency difference between fog and cloud processing to be observed visually.

### Dashboard Screenshot

The `images/` directory contains screenshots of the live Grafana dashboard.

### Local Setup

Grafana can be connected to the project's InfluxDB instance running locally.

> The exact connection settings may need to be modified depending on the environment.
