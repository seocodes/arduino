const int pinup = 3; 
const int pinled1 = 4;
const int pinled2 = 5;
bool but0 = true;
bool aux = 0;
bool estado = 0;


void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinup, INPUT);
}

void loop() {
  but0 = digitalRead(pinup);
   if (but0 == true){
    if (aux == 0){
      aux = 1;       //o auxiliar serve para evitar que o estado fique constantemente mudando enquanto o botao está apertado.
      estado = !estado;
    }
   }
   else{
    aux = 0;
   }

   digitalWrite(pinled1, estado);
}

   
  
