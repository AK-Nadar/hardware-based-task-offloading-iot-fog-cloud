# Linux Environment & Setup

This project uses Linux for the fog/cloud-side components of the
IoT-Fog-Cloud architecture, including Mosquitto, Node-RED, InfluxDB
and Grafana.

---

## 1. Basic Privileged Access

Switch to the root user when required:

```bash
sudo su -
```
## 2. Mosquitto MQTT Broker

Mosquitto is used as the MQTT broker for communication between the
ESP8266 IoT device and the Node-RED fog layer.

Install Mosquitto and MQTT Clients
```
sudo apt install mosquitto mosquitto-clients -y
```
Start, Enable & Check Mosquitto
```
sudo systemctl enable mosquitto
sudo systemctl start mosquitto
sudo systemctl status mosquitto
```
## Test MQTT Locally
### Terminal 1 — Subscribe
```
mosquitto_sub -h localhost -t test/topic
```
### Terminal 2 — Publish
```
mosquitto_pub -h localhost -t test/topic -m "Hello AK"
```
The message published from Terminal 2 should appear in Terminal 1.

## Project MQTT Topic

The project uses: `esp8266/data`

Subscribe to the project's MQTT topic:
```
mosquitto_sub -h localhost -t esp8266/data
```

## 3. Node-RED

Node-RED is used as the fog-level processing layer.

### Install Node.js and npm
```
sudo apt install nodejs npm -y
sudo npm install -g --unsafe-perm node-red
```
Start Node-RED in new terminal
```
node-red
```
Node-RED can then be accessed through its web interface.

### Node-RED Dashboard

The project uses Node-RED for:

- Receiving MQTT data
- Processing temperature data
- Threshold checking
- Alert generation
- Fog-level processing
- Forwarding processed data to InfluxDB
- Dashboard visualization

## 4. InfluxDB

InfluxDB is used as the time-series database for storing temperature
and latency-related data.

Install InfluxDB
```
sudo apt install influxdb -y
```
Start, Enable & Check InfluxDB
```
sudo systemctl start influxdb
sudo systemctl enable influxdb
sudo systemctl status influxdb
```
Install InfluxDB Client
```
sudo apt install influxdb-client
```
Open InfluxDB Shell
```
influx
```
Create Project Database
Inside the InfluxDB shell:
```
CREATE DATABASE iot_temperature_shree
SHOW DATABASES
USE iot_temperature_shree
SHOW MEASUREMENTS
temperature
SELECT * FROM temperature
```

## 5. Grafana

Grafana is used as the visualization layer for the project.

Install Grafana

The Grafana repository and required GPG key are configured before
installing the package.

Install Grafana:
```
sudo apt install grafana -y
sudo systemctl start grafana-server
sudo systemctl enable grafana-server
sudo systemctl status grafana-server
```
Grafana is accessed locally through:
`http://localhost:3000`

## 6. Grafana + InfluxDB

Grafana uses InfluxDB as the project's data source.

The project database is:
`iot_temperature_shree`

The main measurement is:
`temperature`

Grafana is used to visualize:
- Live temperature
- Temperature trend
- Fog latency
- Cloud latency
- Fog vs Cloud latency comparison
- Recent stored data

## 7. Complete Project Data Flow

The Linux-side components form the following processing path:
```
ESP8266
   |
   | MQTT
   v
Mosquitto MQTT Broker
   |
   v
Node-RED
   |
   | Processed data
   v
InfluxDB
   |
   v
Grafana
```

## 8. Project Verification

The complete system can be verified layer by layer:

MQTT
```
mosquitto_sub -h localhost -t esp8266/data
```
Verify that temperature messages from the ESP8266 are received.

Node-RED

Verify that the MQTT input receives the ESP8266 data and that the
processing flow executes correctly.

**InfluxDB**
```
influx
```
Then:
```
USE iot_temperature_shree
SHOW MEASUREMENTS
SELECT * FROM temperature
```
Verify that temperature and latency-related data are being stored.
**Grafana**
Open:
`http://localhost:3000`
Verify that the project dashboard displays the stored data and
latency comparison.


