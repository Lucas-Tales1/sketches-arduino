#include <Wire.h> // Biblioteca para comunicação I²C
#include <VL53L0X.h> // Biblioteca do sensor de laser utilizado

VL53L0X sensor;

void setup() {
  Wire.begin(); // Inicia a comunicação I²C e define automaticamente os pinos SDA e SCL
  Serial.begin(9600);

  if (!sensor.init()) {
    Serial.println("Falha ao iniciar VL53L0X");
    while (1);
  }

  sensor.setTimeout(500); // se a medição demorar mais de 500 milissegundos considera erro
  sensor.startContinuous(); // coloca o VL53L0X em modo de medição contínua
}

void loop() {
  unsigned int distancia = sensor.readRangeContinuousMillimeters(); // se não for uma medição contínua, mas sim pontual: sensor.readRangeSingleMillimeters()

  if (sensor.timeoutOccurred()) {
    Serial.println("Timeout!");
  } else {
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" mm");
  }

  delay(200);
}
