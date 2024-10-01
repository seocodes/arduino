const int pinup = 2;
const int pindown = 3;  
const int pinled1 = 4;
const int pinled2 = 5;
const int pinled3 = 6;
const int pinled4 = 7;
int count = 0;
bool but1 = false;
bool but2 = false;
int aux1 = 0;
int aux2 = 0;

void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pinup, INPUT);
  pinMode(pindown, INPUT);
  Serial.begin(9600);
}

void loop() {
  but1 = digitalRead(pinup);
  but2 = digitalRead(pindown);
  if (but1 == true){
    if (aux1 == 0){
      count++;
      aux1 = 1;
    }
  }
   else{
      aux1 = 0;
   }
  if (but2 == true){
    if (aux2 == 0){
      count--;
      aux2 = 1;
    }
  }
   else{
      aux2 = 0;
  }
  if (count > 15){
    count  = 15;
  }
  if (count < 0){
    count = 0;
  }
  Serial.println(count);
  switch(count){
    case 0:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 0);
      break;
    case 1:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 1);
      break;
    case 2:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 0);
      break;
    case 3:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 1);
      break;
    case 4:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 0);
      break;
    case 5:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 1);
      break;
    case 6:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 0);
      break;
    case 7:
      digitalWrite(pinled1, 0);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 1);
      break;
    case 8:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 0);
      break;
    case 9:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 1);
      break;
    case 10:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 0);
      break;
    case 11:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 0);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 0);
      break;
    case 12:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 0);
      break;
    case 13:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 0);
      digitalWrite(pinled4, 1);
      break;
    case 14:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 0);
      break;
    case 15:
      digitalWrite(pinled1, 1);
      digitalWrite(pinled2, 1);
      digitalWrite(pinled3, 1);
      digitalWrite(pinled4, 1);
      break;
    default:
      break;
  }
}
