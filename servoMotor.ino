// script simples para usar um servo motor 

// import da biblioteca 
#include <Servo.h>

// instaciando o objeto servo
Servo meuServo;

void setup() {
  Serial.begin(9600);
  // vinculando o servo ao pino 3
  meuServo.attach(3);
}

void loop() {
  // move para 0°
  meuServo.write(0);
  delay(1000);
  meuServo.write(90);
  delay(1000);
  meuServo.write(180);
  delay(1000);
}
