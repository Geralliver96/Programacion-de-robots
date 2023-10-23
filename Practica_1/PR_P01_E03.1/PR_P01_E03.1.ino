int Pin_EN = 11; 
int Pin_A = 12;
int Pin_B = 13;

void setup() {
  pinMode(Pin_EN, OUTPUT);
  pinMode(Pin_A, OUTPUT); 
  pinMode(Pin_B, OUTPUT);
}

void loop() {

  // a) Incremental hasta máxima velocidad en horario
  for(int i=0; i<=255; i++){
    analogWrite(Pin_EN, i);  
    digitalWrite(Pin_A, HIGH);
    digitalWrite(Pin_B, LOW);
    delay(20); 
  }
  
  // b) Mantiene máxima velocidad por 3 segs
  analogWrite(Pin_EN, 255);
  delay(3000);

  // c) Decremental hasta detenerse
  for(int i=255; i>=0; i--){
    analogWrite(Pin_EN, i);
    delay(20);
  }

  // d) Apagado por 3 segs
  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);  
  delay(3000);

  // e) Repite en sentido antihorario
  for(int i=0; i<=255; i++){
    analogWrite(Pin_EN, i);
    digitalWrite(Pin_A, LOW);
    digitalWrite(Pin_B, HIGH);
    delay(20);
  }
//FAKIU6445
  analogWrite(Pin_EN, 255);
  delay(3000);

  for(int i=255; i>=0; i--){
    analogWrite(Pin_EN, i);
    delay(20);
  }

  digitalWrite(Pin_A, LOW);
  digitalWrite(Pin_B, LOW);
  delay(3000);
}