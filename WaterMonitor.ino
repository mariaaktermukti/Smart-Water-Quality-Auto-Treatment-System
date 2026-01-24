#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pins
const int phPin = A0;
const int tdsPin = A1;
const int oneWireBus = 2;   // DS18B20

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);

  sensors.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  // Read pH
  int phRaw = analogRead(phPin);
  float phValue = (phRaw * 14.0) / 1023.0;

  // Read TDS
  int tdsRaw = analogRead(tdsPin);
  float tdsValue = (tdsRaw * 500.0) / 1023.0; // ppm approx

  // Read Temperature
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  // Water safety check
  bool phSafe   = (phValue >= 6.5 && phValue <= 8.5);
  bool tdsSafe  = (tdsValue <= 500);
  bool tempSafe = (temperatureC <= 35);

  bool waterSafe = phSafe && tdsSafe && tempSafe;

  // OLED display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.print("pH   : ");
  display.print(phValue, 2);

  display.setCursor(0,12);
  display.print("TDS  : ");
  display.print(tdsValue, 0);
  display.print(" ppm");

  display.setCursor(0,24);
  display.print("Temp : ");
  display.print(temperatureC, 1);
  display.print(" C");

  display.setCursor(0,40);
  display.print("WATER: ");

  if (waterSafe) {
    display.print("SAFE");
  } else {
    display.print("NOT SAFE");
  }

  display.display();
  delay(1000);
}
