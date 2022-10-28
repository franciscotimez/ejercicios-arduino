// Consigna:
// Conectar:
// - Un pulsador con resistencia de pull_up.

// Leer el pulsador, imprimir por consola los 4 estados posibles del pulsador.

// Definicion de pines
#define PULSADOR1_PIN 7

// Variables
int pulsador1_estado_anterior = 6;

void setup()
{
  Serial.begin(115200);

  // Inicializo pines
  pinMode(PULSADOR1_PIN, INPUT);
  pulsador1_estado_anterior = digitalRead(PULSADOR1_PIN);
}

void loop()
{
  leer_pulsador(PULSADOR1_PIN, pulsador1_estado_anterior);
  delay(500);
}

void leer_pulsador(int pin, int &estado_anterior)
{
  int estado_actual = digitalRead(pin);

  Serial.print("Pulsador pin: ");
  Serial.print(pin);
  Serial.print("\testado anterior: ");
  Serial.println(estado_anterior);

  if (estado_anterior == 0 && estado_actual == 0)
  {
    Serial.println("Pulsador Bajo");
  }
  if (estado_anterior == 0 && estado_actual == 1)
  {
    Serial.println("Pulsador Subiendo");
  }
  if (estado_anterior == 1 && estado_actual == 0)
  {
    Serial.println("Pulsador Bajando");
  }
  if (estado_anterior == 1 && estado_actual == 1)
  {
    Serial.println("Pulsador Alto");
  }

  estado_anterior = estado_actual;
}
