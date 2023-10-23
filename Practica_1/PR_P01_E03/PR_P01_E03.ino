int Pin_EN = 3;
 int Pin_A = 4;
 int Pin_B = 4;

 void setup() {
 pinMode(Pin_EN, OUTPUT);
 pinMode(Pin_A, OUTPUT);
 pinMode(Pin_B, OUTPUT);

 }

 void loop() {
 // Giramos en un sentido
 digitalWrite(Pin_A,HIGH);
 digitalWrite(Pin_B,LOW);
 analogWrite(Pin_EN,255); // Ponemos el motor a maxima velocidad
 delay(5000);

 // detenemos el motor 2 s
 digitalWrite(Pin_A,LOW);
 digitalWrite(Pin_B,LOW);
 analogWrite(Pin_EN,255);
 delay(2000);
 // Cambiamos direccion el giro del motor
 digitalWrite(Pin_A,LOW);
 digitalWrite(Pin_B,HIGH);
 analogWrite(Pin_EN,127); //Ponemos el motor a velocidad intermedia
 delay(5000);
 // Detenemos el motor 2 S
 digitalWrite(Pin_A,LOW);
 digitalWrite(Pin_B,LOW);
 analogWrite(Pin_EN,255);
 delay(2000);
 }