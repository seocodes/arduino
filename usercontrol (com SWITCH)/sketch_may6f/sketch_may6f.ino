char x;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
  x = Serial.read();
    switch(x) {
      case 'R':
        digitalWrite(led1, HIGH);
        break;
      case 'r':
         digitalWrite(led1, LOW);
        break;
      case 'B':
        digitalWrite(led2, HIGH);
        break;
      case 'b':
        digitalWrite(led2, LOW);
        break;
      case 'G':
        digitalWrite(led3, HIGH);
        break;
      case 'g':
        digitalWrite(led3, LOW);
        break;
      default:
        Serial.println("LETRA NÃO ENCONTRADA, DESLIGANDO LEDS.");
        digitalWrite(led3, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led1, LOW);
        break;
    }
  }
}
