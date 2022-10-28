// Consigna:
// Conectar:
// - Un pulsador con resistencia de pull_up.
// - Un LED amarillo.
// - Un LED rojo.

// Leer el pulsador, con el flanco de bajada del pulsador accionar el LED amarillo, y con el flanco de subida accionar el LED Rojo.

// Definicion de pines
#define PULSADOR1_PIN 7
#define LED_AMARILLO_PIN 2
#define LED_ROJO_PIN 3

// Variables
int pulsador1_estado_anterior;

void setup()
{
  Serial.begin(115200);

  // Inicializo pines
  pinMode(PULSADOR1_PIN, INPUT);
  pulsador1_estado_anterior = digitalRead(PULSADOR1_PIN);

  pinMode(LED_AMARILLO_PIN, OUTPUT);
  digitalWrite(LED_AMARILLO_PIN, LOW);

  pinMode(LED_ROJO_PIN, OUTPUT);
  digitalWrite(LED_ROJO_PIN, LOW);
}

void loop()
{
  int pulsador1_estado;
  pulsador1_estado = leer_pulsador(PULSADOR1_PIN, pulsador1_estado_anterior);

  if (pulsador1_estado == 2)
  {
    digitalWrite(LED_AMARILLO_PIN, !digitalRead(LED_AMARILLO_PIN));
  }

  if (pulsador1_estado == 3)
  {
    digitalWrite(LED_ROJO_PIN, !digitalRead(LED_ROJO_PIN));
  }
  delay(500);
}

// Lee pulsador
// Retorna:
// 0 -> Bajo
// 1 -> Alto
// 2 -> Bajando
// 3 -> Subiendo

int leer_pulsador(int pin, int &estado_anterior)
{
  int estado_actual = digitalRead(pin);
  int estado_pulsador;

  if (estado_anterior == 0 && estado_actual == 0)
    estado_pulsador = 0;
  else if (estado_anterior == 0 && estado_actual == 1)
    estado_pulsador = 3;
  else if (estado_anterior == 1 && estado_actual == 0)
    estado_pulsador = 2;
  else if (estado_anterior == 1 && estado_actual == 1)
    estado_pulsador = 0;

  estado_anterior = estado_actual;
  return estado_pulsador;
}
