int puertoAnalogico = A0;

class Potenciometro {
  private:
    int pin;

  public:
    Potenciometro(int pin) {
      this->pin = pin;
      pinMode(pin, INPUT);
    }

    unsigned int obtenerValor() {
      return analogRead(pin);
    }

    float obtenerVoltaje() {
      unsigned int valor = obtenerValor();
      // Suponiendo que el rango del potenciómetro es de 0 a 1023 y el voltaje es de 0 a 5V
      float voltaje = (valor * 5.0) / 1023.0;
      return voltaje;
    }
};

Potenciometro miPotenciometro(puertoAnalogico);

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned int valorPotenciometro = miPotenciometro.obtenerValor();
  float voltajePotenciometro = miPotenciometro.obtenerVoltaje();

  Serial.print("Valor leído en el potenciómetro (ADC): ");
  Serial.println(valorPotenciometro);

  Serial.print("Voltaje del potenciómetro: ");
  Serial.print(voltajePotenciometro, 2); // Mostrar solo dos decimales
  Serial.println(" V");

  delay(500);
}
