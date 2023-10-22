#include <Servo.h> 

Servo servo_3;

void setup() {

  servo_3.attach(3);

}

void loop() {

  for(int i = 0; i <= 180; i++) {

    servo_3.write(i);
  
  }

  delay(2000);

  for(int i = 180; i >= 0; i--) {

    servo_3.write(i);
  
  }

  delay(2000);

}