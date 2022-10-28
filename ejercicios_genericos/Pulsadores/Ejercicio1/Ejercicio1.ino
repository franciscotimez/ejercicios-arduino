// Consigna:
// Conectar:
// - Un pulsador con resistencia de pull_up.
// - Un LED.

// Leer el pulsador, encender el LED mientras el pulsador esta abierto, y apagarlo mientras el pulsador esta cerrado.

// Definicion de pines
#define PULSADOR1_PIN 7
#define LED_AMARILLO_PIN 2

void setup(){
  Serial.begin(115200);

  // Inicializo pines
  pinMode(PULSADOR1_PIN, INPUT);

  pinMode(LED_AMARILLO_PIN, OUTPUT);
  digitalWrite(LED_AMARILLO_PIN, LOW);
}

void loop(){
  if(digitalRead(PULSADOR1_PIN)) {
    digitalWrite(LED_AMARILLO_PIN, HIGH);
  }
  else {
    digitalWrite(LED_AMARILLO_PIN, LOW);
  }
}