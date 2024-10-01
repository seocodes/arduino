int numero = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Digite um número: ");
}
 
void loop() {
  if (Serial.available() > 0) {
    int numero = Serial.parseInt();
    Serial.print("Você digitou: ");
    Serial.println(numero);
    Serial.println("Digite um número: ");
    
  }
}