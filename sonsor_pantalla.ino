#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define DHTPIN D4
#define DHTTYPE DHT11
#define rojo D3
#define azul D7
#define ANCHO 128
#define ALTO 64
#define OLED_RESET 0
#define i2c_dir 0x3C
Adafruit_SSD1306 oled(ANCHO,ALTO,&Wire,OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Wire.begin();
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, i2c_dir);
  oled.clearDisplay();
  oled.display();
  delay(100);
  
oled.println(F("DHTxx test!"));
dht.begin();
pinMode(rojo, OUTPUT);
pinMode(azul, OUTPUT);

}

void loop() {
delay(1000); //Es un sensor lento, por lo que hay que darle tiempo.
float h = dht.readHumidity();
float t = dht.readTemperature();

if (isnan(h) || isnan(t)) {
oled.println(F("Failed to read from DHT sensor!"));
return;
}

  oled.clearDisplay();
  oled.setTextColor(WHITE);
  
  oled.setTextSize(1);
  oled.setCursor(35,20);
  oled.print(F("Humedad:"));
  oled.setTextSize(1);
  oled.setCursor(35,30);
  oled.print(h);
  oled.print("%");
  oled.setTextSize(1);
  oled.setCursor(35,40);
  oled.print(F("Temperatura:"));
  oled.setTextSize(1);
  oled.setCursor(35,50);
  oled.print(t);
  oled.print(F("°C "));
  
  
 
  oled.display();

  if (isnan(h) || isnan(t)) {
Serial.println(F("Failed to read from DHT sensor!"));
return;
}

Serial.print(F("Humedad: "));
Serial.print(h);
Serial.print(F("% Temperatura: "));
Serial.print(t);
Serial.println(F("°C "));

if(h>=50){
  digitalWrite(azul, HIGH);
}
if(h<50){
  digitalWrite(azul, LOW);
}

if(t>25){
  digitalWrite(rojo, HIGH);
}else {
  digitalWrite(rojo, LOW);
}

}
         
