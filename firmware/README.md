# ESP8266 Firmware

This directory contains the ESP8266 firmware used for the hardware implementation of the IoT-Fog-Cloud task offloading system.

## Hardware

- ESP8266MOD microcontroller
- LM35 analog temperature sensor
- 3 × LEDs
- Wi-Fi connectivity

## Sensor

The LM35 temperature sensor is connected to the ESP8266 analog input A0.

The sensor provides temperature measurements that are processed by the ESP8266 before being transmitted through MQTT.

## LED Indicators

The firmware uses three LEDs connected to:
- D5
- D6
- D7

The LEDs provide local temperature/status indication at the IoT layer.

## Communication

The ESP8266 connects to the Wi-Fi network and publishes temperature data using MQTT.

### MQTT Topic

`esp8266/data`

### MQTT Payload

The firmware publishes temperature information in JSON format.

```json
{
  "temp": 32.3,
  "time": 123456789
}
```
The exact timestamp value depends on the running device.

### Firmware Functions
The firmware is responsible for:
- Reading temperature from the LM35 sensor
- Processing temperature values
- Applying local threshold logic
- Controlling LED indicators
- Connecting to Wi-Fi
- Connecting to the MQTT broker
- Publishing sensor data to the MQTT topic

### Development Environment
- Arduino IDE
- ESP8266 board support
- ESP8266WiFi library
- PubSubClient MQTT library

### Configuration

Before uploading the firmware to another ESP8266 device, configure:

- Wi-Fi SSID
- Wi-Fi password
- MQTT broker address

Do not commit real passwords, tokens, or other credentials to the repository.

### Uploading the Firmware
1. Open `ESP8266_ResearchProject.ino` in Arduino IDE.
2. Select the appropriate ESP8266 board.
3. Select the correct COM port.
4. Configure the Wi-Fi and MQTT settings.
5. Compile the firmware.
6. Upload it to the ESP8266.
7. Open Serial Monitor to verify the device connection and sensor readings.

### Firmware File

The main firmware source is:

`ESP8266_ResearchProject.ino`
