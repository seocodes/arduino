const int pinZSH = 3;
const int pinZSL = 4;
const int pinPB1 = 8;
const int pinPB2 = 9;
const int M1 = 5;
const int M2 = 6;
int auxCima = 0;
int auxBaixo = 0;

void setup() {
  pinMode(pinZSH, INPUT_PULLUP);
  pinMode(pinZSL, INPUT_PULLUP);
  pinMode(pinPB1, INPUT_PULLUP);
  pinMode (pinPB2, INPUT_PULLUP);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
  bool ZSH = !digitalRead(pinZSH);
  bool ZSL = !digitalRead(pinZSL);
  bool PB1_Estado = !digitalRead(pinPB1);
  bool PB2_estado = !digitalRead(pinPB2);

  if (PB1_Estado && !ZSH && !auxBaixo){
      digitalWrite(M1, HIGH); 
      auxCima = 1;
}  else{
        digitalWrite(M1, LOW);
        auxCima = 0;
  }
  
  if (PB2_estado && !ZSL && !auxCima){
        digitalWrite(M2, HIGH); 
        auxBaixo = 1;
}  else{
        digitalWrite(M2, LOW);
        auxBaixo = 0;
  }
}
