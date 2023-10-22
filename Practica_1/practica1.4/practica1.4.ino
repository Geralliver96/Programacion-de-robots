//Pines para el motor  
int Pin_EN = 11;
int Pin_A = 12;  
int Pin_B = 13;

int puertoAnalogico = A0; 
class Potenciometro {

  private:
     int pin;
  
  public:

    Potenciometro(int pin) {
      this->pin = pin;
      pinMode(pin, INPUT);
    }

    int obtenerValor() {
      return analogRead(pin);
    }

    float obtenerVoltaje() {
      int valor = obtenerValor();
      float voltaje = valor * (5.0 / 1023.0);
      return voltaje;
    }

};

//Objeto potenciometro
Potenciometro miPotenciometro(puertoAnalogico);  

void setup() {

  //Configurar A0 como entrada analógica
  pinMode(puertoAnalogico, INPUT);  

  //Config pines motor
  pinMode(Pin_EN, OUTPUT);
  pinMode(Pin_A, OUTPUT);
  pinMode(Pin_B, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  //Leer valor del potenciometro
  int valor = miPotenciometro.obtenerValor();
  
  //Convertir a rango 0-255 para analogWrite
  int velocidad = map(valor, 0, 1023, 0, 255);  

  //Establecer velocidad al motor
  analogWrite(Pin_EN, velocidad);

  //Sentido de giro
  digitalWrite(Pin_A, HIGH);
  digitalWrite(Pin_B, LOW);

  //Imprimir velocidad
  Serial.print("Velocidad motor: ");
  Serial.println(velocidad);
  
  delay(100);
}