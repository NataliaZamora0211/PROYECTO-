#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
 
//Asignamos nombre de nuestros pines de Arduino a utilizar
#define pwm 2
const int sensorDHT=A2;

//Declaramos 2 variables tipo entero para almacenar los datos leidos del sensor
int temp;

//Le asignamos un nombre a nuestro objeto
DHT dht (sensorDHT,DHT11);

//Configuaraciòn inicial de la Tarjeta Arduino
void setup(){
  Serial.begin(9600); //Iniciamos comunicaciòn con la PC a 9600 Batios
  pinMode(pwm,OUTPUT); //Le indicamos que el ventilador (pin 8) serà de salida
  dht.begin(); //Iniciamos nuestro sensor DHT11

// Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  
  }

void loop(){
      //humedad= dht.readHumidity(); //Funcion incluida en la libreria. Permite leer la humedad.
      temp= dht.readTemperature(); //Permite leer la temperatura.


      //Se imprime en pantalla los datos leìdos.
      Serial.print("Temperatura: ");
      Serial.print(temp);
      Serial.println("ºC"); //Tempertura: 29ºC
      //Serial.print("Humedad: ");
      //Serial.print(humedad);
      //Serial.print("%");
      Serial.println(" ");
      Serial.println(" ");

        int sen1=analogRead(A2);
          lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.print(temp);   // Printing temperature on LCD
  lcd.print("C");
  lcd.setCursor(0,1);

      //Pausa de 1 Segundo para poder apreciar los datos.
      delay(1000);

      if (temp<26){ //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores Off");
        digitalWrite(pwm,LOW); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura      
        lcd.print("Ventiladores Off");  
        delay(1000);
        }

        else if (temp==26)
        { //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores 20%");
        digitalWrite(pwm, 51); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura
        lcd.print("Ventiladores 20%");
        delay(1000);
        }

        else if(temp==27)
        { //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores 40%");
        digitalWrite(pwm, 102); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura
        lcd.print("Ventiladores 40%");
        delay(1000);
        }

        else if(temp==28)
        { //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores 60%");
        digitalWrite(pwm, 153); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura
        lcd.print("Ventiladores 60%");
        delay(1000);
        }

        else if(temp==29)
        {
        //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores 80%");
        digitalWrite(pwm, 204); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura
        lcd.print("Ventiladores 80%");
        delay(1000);
        }

         else if(temp>29)
         { //Condición para mantener el ambiente fresco.
        Serial.println("Ventiladores 100%");
        digitalWrite(pwm, 255); //Encendemos el ventilador
        temp= dht.readTemperature(); //Volvemos a leer la temperatura
        lcd.print("Ventiladores 1000%");
        delay(1000);
         }

         }
         

