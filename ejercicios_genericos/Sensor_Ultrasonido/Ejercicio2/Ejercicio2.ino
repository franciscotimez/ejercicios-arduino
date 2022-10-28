// Consigna
// Conectar:
// - Un Sensor de distancia por ultrasonido

// Leer el valor del sensor y mostrar la Distancia medida por el monitor Serial. Encapsular el funcionamiento del sensor en una funcion.


const int Trigger = 6; // Pin digital 2 para el Trigger del sensor
const int Echo = 5;    // Pin digital 3 para el Echo del sensor

void setup()
{
  Serial.begin(115200);         // iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT);   // pin como salida
  pinMode(Echo, INPUT);       // pin como entrada
  digitalWrite(Trigger, LOW); // Inicializamos el pin con 0
}

void loop()
{
  long distancia = leer_distancia(Trigger,Echo);

  Serial.print("Distancia: ");
  Serial.print(distancia); // Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100); // Hacemos una pausa de 100ms
}

long leer_distancia(int trig_pin, int echo_pin){
  long t; // timepo que demora en llegar el eco
  long d; // distancia en centimetros

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10); // Enviamos un pulso de 10us
  digitalWrite(trig_pin, LOW);

  t = pulseIn(echo_pin, HIGH); // obtenemos el ancho del pulso
  d = t / 59;              // escalamos el tiempo a una distancia en cm
  return d;
}