const int pinLed = 13;
bool estado = 0;
const long intervalo = 2000;
unsigned long tempoAnt = 0;

void setup() {
  pinMode(pinLed, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnt >= intervalo){
    tempoAnt = tempoAtual;
    if (estado == 0) {
      estado = 1;
    } else {
        estado = 0;
    }
  digitalWrite(pinLed, estado);
  }
}
