#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
  Serial.print(F("humidity,celsius,farenheit,hic,hif\n"));

}

void loop() {
  delay(5000);
  float hum = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  if (isnan(hum) || isnan(tempC) || isnan(tempF)) {
    Serial.println(F("NULL"));
    return;
  }

  float hiF = dht.computeHeatIndex(tempF, hum);
  float hiC = dht.computeHeatIndex(tempC, hum, false);
  Serial.print(hum);
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.print(hiC);
  Serial.print(",");
  Serial.print(hiF);
  Serial.print("\n");
}
