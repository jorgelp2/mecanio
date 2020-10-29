#include <Wire.h>
#include <Adafruit_INA219.h>

float current;
//float cf;
int aux;
//float b;

Adafruit_INA219 ina219;

void setup() {
  aux = 0;
  /*
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }
*/
  uint32_t currentFrequency;
  ina219.begin();
    
  //Serial.println("Hello!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).///
  /*
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }*/
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  //Serial.println("Measuring voltage and current with INA219 ...");
  pinMode(22, OUTPUT);
  digitalWrite(22 , HIGH);
  delay(1500);
// Fin de configuracion-----------------------------------------------------------------------------------------
}



void loop() {
  //delay(1500);
  unsigned long antes=millis();
  current = ina219.getCurrent_mA();
  //b = cf - current;
  //Serial.print("Current:       "); Serial.print(current/1000); Serial.println("A");
  //Serial.print("Cf:       "); Serial.print(cf); Serial.println("A");
  //Serial.print("b ez       "); Serial.print(b); Serial.println(" A");
  //delay(1500);
  
  if (current <5){
  //if (b < -(current*55)/100){
    aux = aux + 1;
    //Serial.print("Current:       "); Serial.print(current); Serial.println(" mA"); 
    //Serial.println("");

    if (aux < 2){
      delay(150);
      current = ina219.getCurrent_mA();
    }
  if (aux == 2){
    digitalWrite(22 , LOW);
    delay(10000);
    digitalWrite(22 , HIGH);
    delay(1500);
    aux =0;
    
  }
    }
  //cf = current;
  unsigned long despues=millis();  
  unsigned long transcurridos= despues-antes;
  //Serial.print("tiempo:       "); Serial.print(transcurridos); Serial.println("S");
}
