#include <Wire.h>
#include <Adafruit_INA219.h>

float current;
int aux;

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  aux = 0;

  uint32_t currentFrequency;
  ina219.begin();

  pinMode(22, OUTPUT);
  
// Fin de configuracion-----------------------------------------------------------------------------------------
}



void loop() {
  //delay(1500);
  if (Serial.available() > 0)
   {
      String str = Serial.readStringUntil('\n');
      String fila = str.substring(0,2);
      String columna = str.substring(2,4);   
      long tamano = sizeof(str);
      //long tamano = strlen(str);
      int data = str.toInt();
      int f = fila.toInt();
      int c = columna.toInt();
      //DEBUG(data);
      Serial.print("numero: "); Serial.print(data); //Serial.println("A");
      Serial.print("longitud : "); Serial.print(tamano); //Serial.println("A");
      Serial.print("fila: "); Serial.print(f); //Serial.println("A");
      Serial.print("columna: "); Serial.print(c); //Serial.println("A");
      Serial.println("");
      //invento Se puede comentar
    //enciendo motor--------------
      digitalWrite(22 , HIGH);
      delay(1500);
      while(1){
       unsigned long antes=millis();
       current = ina219.getCurrent_mA();
  
       if (current <5){
         aux = aux + 1;
      
         if (aux < 2){
           delay(150);
           current = ina219.getCurrent_mA();
            }
       if (aux == 2){
         digitalWrite(22 , LOW);
         //delay(10000);
         //digitalWrite(22 , HIGH);
         //delay(1500);
         aux =0;
         break;
       }
       unsigned long despues=millis();  
       unsigned long transcurridos= despues-antes;
       }
  
     //delay(10000);
      }
   }
  
  //Serial.print("tiempo:       "); Serial.print(transcurridos); Serial.println("S");
}
