# Hardware-Based Efficient Task Offloading in IoT-Fog-Cloud

A hardware-based IoT-Fog-Cloud system designed to demonstrate efficient task offloading for real-time temperature monitoring.

The system uses an ESP8266 microcontroller with an LM35 temperature sensor at the IoT layer, Node-RED for fog-level processing and decision-making, and InfluxDB with Grafana for cloud-level storage and visualization.

## 📄 Published Research

This project is based on the research paper:

**Hardware-Based Efficient Task Offloading in IoT-Fog-Cloud**

**Authors:**

- Nadar Akshayashree Stephan Selvaraj
- Maya Nair

**Journal:** Journal of IoT-based Distributed Sensor Networks  
**Volume:** 3  
**Issue:** 2  
**Pages:** 27–39  
**Published:** August 08, 2026

### DOI

[https://doi.org/10.46610/JIBDSN.2026.v03i02.003](https://doi.org/10.46610/JIBDSN.2026.v03i02.003)

### Publication

[View the published article](https://matjournals.net/engineering/index.php/JIBDSN/article/view/3973)

### Citation
N. A. S. Selvaraj and M. Nair,
"Hardware-Based Efficient Task Offloading in IoT-Fog-Cloud,"
Journal of IoT-based Distributed Sensor Networks,
vol. 3, no. 2, pp. 27-39, Aug. 2026.

---

## 🎯 Project Objective

The objective of this project is to demonstrate efficient task offloading between IoT, fog and cloud layers for real-time applications.

Time-critical operations are processed closer to the data source at the fog layer, while non-critical tasks such as long-term storage and visualization are handled by the cloud layer.

---

## System Architecture

```
                    IoT Layer
              ┌─────────────────┐
              │    ESP8266      │
              │      +          │
              │     LM35        │
              │                 │
              │  Local Alerts   │
              └────────┬────────┘
                       │
                       │ MQTT
                       ▼
              ┌─────────────────┐
              │  MQTT Broker    │
              │   Mosquitto     │
              └────────┬────────┘
                       │
                       ▼
                    Fog Layer
              ┌─────────────────┐
              │    Node-RED     │
              │                 │
              │ Data Processing │
              │ Threshold Logic │
              │ Alert Generation│
              └────────┬────────┘
                       │
                       │ Processed Data
                       ▼
                   Cloud Layer
              ┌─────────────────┐
              │    InfluxDB     │
              │ Time-Series DB  │
              └────────┬────────┘
                       │
                       ▼
              ┌─────────────────┐
              │     Grafana     │
              │ Visualization   │
              └─────────────────┘
```

## 🔌Hardware
- ESP8266 microcontroller
- LM35 analog temperature sensor
- 3 × LEDs
- Wi-Fi router
- Voltage divider for LM35 ADC input

The LM35 sensor is connected to the ESP8266 A0 pin.

LED indicators are connected to:
- D5
- D6
- D7

## 💻 Software & Technologies

| Technology   | Purpose                   |
| ------------ | ------------------------- |
| Arduino IDE  | ESP8266 programming       |
| Embedded C++ | ESP8266 firmware          |
| MQTT         | IoT-to-Fog communication  |
| Mosquitto    | MQTT broker               |
| Node-RED     | Fog processing and alerts |
| Ubuntu VM    | Fog computing environment |
| InfluxDB     | Time-series data storage  |
| Grafana      | Data visualization        |
| Wi-Fi Router | Network communication     |

## 📡 Data Flow
```
ESP8266
   │
   │ Temperature Data
   ▼
MQTT Topic: esp8266/data
   │
   ▼
Mosquitto MQTT Broker
   │
   ▼
Node-RED
   │
   ├── Threshold Processing
   ├── Alert Generation
   └── Dashboard
   │
   ▼
InfluxDB
   │
   ▼
Grafana
```

## 🚨 Task Offloading

*Time-Critical Tasks*

Handled at the IoT/Fog layers:
- Temperature threshold checking
- Alert generation
- LED control

*Non-Critical Tasks*

Handled at the cloud layer:
- Data storage
- Historical analysis
- Visualization

This reduces dependency on cloud processing for immediate responses.

## 📊 Experimental Results

The system was evaluated using real hardware and a real network environment.

*Latency Comparison*

| Layer | Average Latency |
| ----- | --------------: |
| Fog   |          103 ms |
| Cloud |          271 ms |

The experimental results showed approximately 62% lower latency at the fog layer compared with the cloud layer.

*Experimental Trials*

| Trial | Fog Latency | Cloud Latency |
| ----: | ----------: | ------------: |
|     1 |      105 ms |        317 ms |
|     2 |       95 ms |        248 ms |
|     3 |       92 ms |        269 ms |
|     4 |      108 ms |        211 ms |
|     5 |      117 ms |        309 ms |

**📂 Repository Structure**
```
├── firmware/       # ESP8266 firmware
├── node-red/       # Node-RED flows
├── mqtt/           # MQTT configuration/documentation
├── influxdb/       # InfluxDB configuration/documentation
├── grafana/        # Grafana dashboard/documentation
├── images/         # Project screenshots and photographs
├── docs/           # Architecture and publication information
└── results/        # Experimental results
```

## ⚠️ Limitations

The current implementation was evaluated using:
- One ESP8266 device
- One fog node
- A local network environment
- Five experimental trials

## 🔭 Future Work

Future work includes:

- Multiple IoT devices
- Distributed fog nodes
- Intelligent task offloading algorithms
- Security mechanisms
- Throughput analysis
- Packet delivery analysis
- Energy consumption studies

## 🔬 Research Contribution

This project demonstrates a practical hardware-based IoT-Fog-Cloud implementation rather than relying solely on simulation.

The implementation combines:

**ESP8266 + LM35 + MQTT + Node-RED + InfluxDB + Grafana**

to demonstrate real-time task processing and latency comparison between fog and cloud layers.

## 📜 License

### Source Code

The original source code and implementation files in this repository
are licensed under the MIT License.

### Published Research

The published research article:

**Hardware-Based Efficient Task Offloading in IoT-Fog-Cloud**

is licensed under **CC BY-NC-ND 4.0** by the authors.

The research article is available through its DOI:

https://doi.org/10.46610/JIBDSN.2026.v03i02.003

The research article, publication certificate, and other third-party
materials are not covered by the MIT License.
