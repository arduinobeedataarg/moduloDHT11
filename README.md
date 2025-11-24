# Proyecto Arduino Uno - Módulos de Sensores

Proyecto de pruebas con Arduino Uno que implementa diferentes tipos de sensores para medición de temperatura, humedad y peso.

## Sensores Utilizados

- **DHT11**: Sensor digital de temperatura y humedad
- **HX711**: Amplificador para celda de carga (sensor de peso)

## Requisitos

### Hardware Necesario

- 1x Arduino Uno
- 1x Sensor DHT11 (Temperatura y Humedad)
- 1x Módulo HX711 con celda de carga
- Cables de conexión (jumpers)
- Cable USB para programación

### Software Necesario

- **Arduino IDE** (versión 1.8.x o superior)
  - Descarga desde: https://www.arduino.cc/en/software

### Librerías Requeridas

Las siguientes librerías deben instalarse en el Arduino IDE:

1. **DHT sensor library** (by Adafruit)
2. **HX711 Arduino Library** (by Bogdan Necula o similar)

#### Instalación de Librerías

1. Abrir Arduino IDE
2. Ir a `Sketch` → `Include Library` → `Manage Libraries...`
3. Buscar "DHT sensor library" e instalar
4. Buscar "HX711" e instalar
5. Reiniciar Arduino IDE

## Estructura del Proyecto

```
moduloDHT11/
├── sensorTemperaturaHumedad/
│   └── main.cpp          # Código para sensor DHT11
├── sensorDePeso/
│   └── main.cpp          # Código para sensor HX711
├── src/
│   └── sensorDePeso.png  # Captura del Arduino IDE con sensor de peso
└── README.md
```

## Módulo 1: Sensor de Temperatura y Humedad (DHT11)

### Descripción

El sensor DHT11 es un sensor digital que mide temperatura y humedad relativa del ambiente.

### Especificaciones

- Rango de temperatura: 0-50°C (±2°C de precisión)
- Rango de humedad: 20-90% HR (±5% de precisión)
- Voltaje de operación: 3-5V DC
- Interfaz digital de un solo cable

### Conexiones

| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| DATA      | Pin 2       |
| GND       | GND         |

### Uso del Código

1. Abrir el archivo `sensorTemperaturaHumedad/main.cpp` en Arduino IDE
2. Verificar que el sensor esté conectado al pin 2
3. Compilar y cargar el código al Arduino
4. Abrir el Monitor Serial a 9600 baudios
5. Observar las lecturas de humedad y temperatura cada 2 segundos

### Formato de Salida

```
Humedad(%) Temperatura(°C)
65.00 24.00
```

**Nota**: La salida está formateada para ser compatible con el Serial Plotter de Arduino.

## Módulo 2: Sensor de Peso (HX711)

### Descripción

El módulo HX711 es un amplificador de precisión para celdas de carga, permitiendo crear una balanza digital.

![Sensor de Peso](src/sensorDePeso.png)

### Especificaciones

- Conversor ADC de 24 bits
- Voltaje de operación: 2.6-5.5V
- Interfaz digital de 2 cables (Data + Clock)
- Soporta celdas de carga de 5kg a 200kg

### Conexiones

| HX711 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| DT (Data) | Pin 3       |
| SCK (Clock)| Pin 2      |

### Calibración del Sensor

El código incluye funcionalidades de calibración:

```cpp
scale.set_scale(2280.f);  // Factor de calibración
scale.tare();             // Poner en cero (tara)
```

**Importante**: El valor `2280.f` debe ajustarse según tu celda de carga específica. Para calibrar:

1. Ejecutar el código sin peso conocido
2. Colocar un peso conocido (ej: 100g)
3. Ajustar el valor hasta obtener la lectura correcta

### Uso del Código

1. Abrir el archivo `sensorDePeso/main.cpp` en Arduino IDE
2. Verificar las conexiones según la tabla anterior
3. Compilar y cargar el código al Arduino
4. Abrir el Monitor Serial a 9600 baudios
5. Observar las lecturas de peso cada 200ms

### Formato de Salida

```
Peso: 125.50 g
```

El sensor promedia 10 lecturas para mayor estabilidad.

## Instrucciones Generales de Uso

### Cargar un Sketch en Arduino

1. Conectar el Arduino Uno a la computadora mediante USB
2. Abrir Arduino IDE
3. Abrir el archivo `.cpp` del módulo deseado
4. Seleccionar placa: `Tools` → `Board` → `Arduino Uno`
5. Seleccionar puerto: `Tools` → `Port` → (seleccionar el puerto COM correspondiente)
6. Hacer clic en el botón "Upload" (→)
7. Esperar la confirmación "Done uploading"

### Visualizar Datos

**Monitor Serial:**
- `Tools` → `Serial Monitor` (o Ctrl+Shift+M)
- Configurar a 9600 baud

**Serial Plotter (para DHT11):**
- `Tools` → `Serial Plotter` (o Ctrl+Shift+L)
- Visualización gráfica en tiempo real

## Solución de Problemas

### Error: "DHT library not found"
- Instalar la librería DHT sensor library desde el Library Manager

### Error: "HX711 library not found"
- Instalar la librería HX711 desde el Library Manager

### Lecturas incorrectas del sensor de peso
- Verificar las conexiones DT y SCK
- Recalibrar usando el método `set_scale()`
- Hacer tare (cero) sin peso sobre la balanza

### Sensor DHT11 devuelve "0 0"
- Verificar conexión del pin de datos (pin 2)
- Verificar alimentación (VCC y GND)
- Esperar unos segundos después de conectar

## Autor

Proyecto desarrollado para pruebas con Arduino Uno y diferentes sensores.

## Licencia

Este proyecto es de código abierto y está disponible para uso educativo.
