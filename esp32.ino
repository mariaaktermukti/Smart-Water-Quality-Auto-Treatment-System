#define BLYNK_TEMPLATE_NAME "Water Quality Monitoring"
#define BLYNK_AUTH_TOKEN "I8TqzBX-kiSCSXz2i9EsRUqTmyHcsdhk"

const char* apiKey = "YBGCV3JZLPK82D5Y";   

// WiFi credentials
char ssid[] = "UIU-STUDENT";
char pass[] = "12345678";

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Sensor Pins
#define pH_Pin A0
#define TDS_Pin A1
#define TEMP_Pin 2      
#define PUMP_Pin 5

OneWire oneWire(TEMP_Pin);
DallasTemperature sensors(&oneWire);

// Global Variables
float pH_value = 7.0;
float TDS_value = 300;
float Temp_value = 30;
String WaterStatus = "SAFE"; 

void setup() {
  Serial.begin(115200);
  pinMode(PUMP_Pin, OUTPUT);
  
  sensors.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // Read Sensors
  pH_value = analogRead(pH_Pin) * 14.0 / 4095;   
  TDS_value = analogRead(TDS_Pin) * 1000.0 / 4095; 
  sensors.requestTemperatures();
  Temp_value = sensors.getTempCByIndex(0);

  // Determine Water Status
  if (pH_value < 6.5 || pH_value > 8.5 || TDS_value > 500) {
    WaterStatus = "UNSAFE";
    digitalWrite(PUMP_Pin, HIGH);
  }
  else if (Temp_value > 50) {
    WaterStatus = "ALERT";
    digitalWrite(PUMP_Pin, LOW);
  }
  else {
    WaterStatus = "SAFE";
    digitalWrite(PUMP_Pin, LOW);
  }

  // Send live data to Blynk
  Blynk.virtualWrite(V0, pH_value);       // pH
  Blynk.virtualWrite(V1, TDS_value);      // TDS
  Blynk.virtualWrite(V2, Temp_value);     // Temp
  Blynk.virtualWrite(V4, digitalRead(PUMP_Pin)); // Pump ON/OFF

  // Serial Monitor
  Serial.print("pH: "); Serial.print(pH_value);
  Serial.print(" | TDS: "); Serial.print(TDS_value);
  Serial.print(" | Temp: "); Serial.print(Temp_value);
  Serial.print(" | Pump: "); Serial.println(digitalRead(PUMP_Pin));

  Blynk.run();
  delay(2000);  
}
