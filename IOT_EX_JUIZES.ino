const int led_aprov = 3;
const int led_reprov = 4;
const int led_empate = 5;
const int pinJ1 = 8;
const int pinJ2 = 9;
const int pinJ3 = 10;
const int pinJ4 = 11;

void setup() {
  pinMode(led_aprov, OUTPUT);
  pinMode(led_reprov, OUTPUT);
  pinMode(led_empate, OUTPUT);
  pinMode(pinJ1, INPUT_PULLUP);
  pinMode(pinJ2, INPUT_PULLUP);
  pinMode(pinJ3, INPUT_PULLUP);
  pinMode(pinJ4, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool but1 = !digitalRead(pinJ1);
  bool but2 = !digitalRead(pinJ2);
  bool but3 = !digitalRead(pinJ3);
  bool but4 = !digitalRead(pinJ4);
  int resultado = but1 + but2 + but3 + but4;
  Serial.println(resultado);

  if (resultado > 2) {
    digitalWrite(led_aprov, HIGH);
    digitalWrite(led_reprov, LOW);
    digitalWrite(led_empate, LOW);
  } else if (resultado == 2) {
    digitalWrite(led_empate, HIGH);
    digitalWrite(led_aprov, LOW);
    digitalWrite(led_reprov, LOW);
  } else {
    digitalWrite(led_reprov, HIGH);
    digitalWrite(led_aprov, LOW);
    digitalWrite(led_empate, LOW);
  }
}
