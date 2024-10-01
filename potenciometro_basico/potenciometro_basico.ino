const int pin_entrada = A0;
const int pin_led = 4;
int valor;
float tensao;

void setup() {
  Serial.begin(9600);
  pinMode(pin_entrada, INPUT);
  pinMode(pin_led, OUTPUT);
}

void loop() {
  valor = analogRead(pin_entrada);
  tensao = float(valor)*5/1023;
  Serial.print("Tensao = ");
  Serial.print(tensao);
  Serial.println(" V");
  if (tensao > 3){
    digitalWrite(pin_led, HIGH);
    }
  else{
    digitalWrite(pin_led, LOW);
  }
}

