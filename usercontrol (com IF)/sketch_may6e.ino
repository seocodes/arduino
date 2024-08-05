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
    if (x == 'R'){
        digitalWrite(led1, HIGH);
  }
    if (x == 'r'){ 
      digitalWrite(led1, LOW);
      }
    if (x == 'B'){
      digitalWrite(led2, HIGH);
  }
    if (x == 'b'){
      digitalWrite(led2, LOW);
  }
    if (x == 'G'){
      digitalWrite(led3, HIGH);
  }
    if (x == 'g'){
      digitalWrite(led3, LOW);
  }
 }
}
