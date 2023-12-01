void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
int lectura = analogRead(A0);

Serial.print("La lectura es:");
Serial.println(lectura);

//lecturas entre 1000-1023
if (lectura >= 1000) {
  Serial .println(">> EL SENSOR ESTA DESCONECTADO O FUERA DEL SUELO <<") ;
}
else if (lectura<1000 && lectura >=600) {
  Serial.println(">> EL SUELO ESTA SECO <<");
  
}
else if (lectura<600 && lectura >=370) { 
  Serial.println(">> EL SUELO ESTA HUMEDO <<");
}
else if (lectura<370) { 
  Serial.println(">> EL SUELO ESTA PRACTICAMENTE EN AGUA <<");
}
delay(1000);
}
