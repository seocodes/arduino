const int pin1 = 3;
const int pin2 = 2;
const int pinled1 = 4;
const int pinled2 = 5;
const int pinled3 = 6;
bool but1 = false;
bool but2 = false;
void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
}

void loop() {
  but1 = digitalRead(pin1);
  but2 = digitalRead(pin2);
    if (but1 && but2) {  //Quando há apenas variáveis no IF, presume-se que é TRUE, se houver um ! na frente, é FALSE.
      digitalWrite(pinled1, HIGH);
    }
    else{
      digitalWrite(pinled1, LOW);
    }
    if (but1 || but2){
      digitalWrite(pinled2, HIGH);
    }
    else{
      digitalWrite(pinled2, LOW);
    }
    if (but1 ^ but2){
      digitalWrite(pinled3, HIGH);
    }
    else{
      digitalWrite(pinled3, LOW);
    }
}
