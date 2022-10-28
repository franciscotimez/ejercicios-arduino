// Consigna:
// Conectar:
// - Un pulsador con resistencia de pull_up.
// - Un LED.

// Leer el pulsador, con un pulso encender el LED y con otro pulso apargar el LED.

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
  if(!digitalRead(PULSADOR1_PIN)) {
    digitalWrite(LED_AMARILLO_PIN, !digitalRead(LED_AMARILLO_PIN));
  }
  delay(200);
}