#include <Servo.h>

Servo servo_3;  
int potPin = A0; //Pin de entrada del potenciómetro

void setup() {
  servo_3.attach(3); 
  Serial.begin(9600);
}

void loop() {

  // Leer valor del potenciómetro
  int potValue = analogRead(potPin);  

  // Mapear el valor a un ángulo entre 0 y 180 grados
  int angle = map(potValue, 0, 1023, 0, 180);

  // Establecer posición al servo 
  servo_3.write(angle);
   Serial.print("Valor leído en el potenciómetro (ADC): ");
  Serial.println(potValue);

  Serial.print("Voltaje del angulo: ");
  Serial.println(angle, DEC); 

  delay(500);
}