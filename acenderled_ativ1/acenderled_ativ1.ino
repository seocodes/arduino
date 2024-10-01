const int pinup = 3;
const int pindown = 2;  
const int pinled1 = 4;
bool but0 = false;
bool but1 = false;

void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinup, INPUT);
  pinMode(pindown, INPUT);
}

void loop() {
  but0 = digitalRead(pinup);
  but1 = digitalRead(pindown);
  if (but0 == true){
    digitalWrite(pinled1, 1);
  }
  if (but1 == true){
    digitalWrite(pinled1, 0);
      }  
}
