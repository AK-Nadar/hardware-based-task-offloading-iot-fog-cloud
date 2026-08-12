#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// MQTT Broker IP
const char* mqtt_server = "YOUR_MQTT_BROKER_IP";

WiFiClient espClient;
PubSubClient client(espClient);

// LED Pins
#define LED1 D5
#define LED2 D6
#define LED3 D7

float temperature = 0;

// Timing variables
unsigned long lastReadTime = 0;
const long interval = 1000;

// Blink control
unsigned long lastBlinkTime = 0;
bool ledState = false;

// WiFi
void setup_wifi() {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

// MQTT reconnect
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Connected!");
    } else {
      Serial.println("Retry...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("\nESP STARTED");

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {

  if (!client.connected()) reconnect();
  client.loop();

  unsigned long currentTime = millis();

  // 🔹 Read sensor once per interval
  if (currentTime - lastReadTime >= interval) {

    lastReadTime = currentTime;

    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (3.3 / 1023.0);
    temperature = voltage * 100;

    Serial.print("Temp: ");
    Serial.println(temperature);

    // LED LOGIC
    if (temperature < 37) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
    else if (temperature >= 37 && temperature <= 40) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
    }

    // Send to MQTT
    char msg[100];
    unsigned long timestamp = millis();

    sprintf(msg, "{\"temp\":%.2f,\"time\":%lu}", temperature, timestamp);
    client.publish("esp8266/data", msg);
  }

  // 🔥 NON-BLOCKING BLINK
  if (millis() - lastBlinkTime >= 2000) {

    lastBlinkTime = millis();
    ledState = !ledState;

    if (temperature > 40) {
      digitalWrite(LED1, ledState);
      digitalWrite(LED2, ledState);
      digitalWrite(LED3, ledState);
    }
  }
}
