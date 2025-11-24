#include "HX711.h"

HX711 scale;

#define DT 3     // Pin DT del HX711
#define SCK 2    // Pin SCK del HX711

void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK);

  Serial.println("Inicializando balanza...");

  scale.set_scale(   -23500);  // Sin calibración aún
  scale.tare();       // Pone el peso inicial en 0
  Serial.println("Listo.");
}

void loop() {
  Serial.print("Peso: ");
  Serial.print(scale.get_units(10));  // Promedia 10 lecturas
  Serial.println(" g");

  delay(200);
}
