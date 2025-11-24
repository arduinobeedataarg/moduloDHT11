#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humedad = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(humedad) || isnan(temp)) {
    Serial.println("0 0");  
    return;
  }

  // Formato para Serial Plotter: valores separados por espacio
  Serial.print(humedad);
  Serial.print(" ");
  Serial.println(temp);

  delay(2000);
}
