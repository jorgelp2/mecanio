void setup()
{
   Serial.begin(9600);
}
 
void loop()
{
 
   if (Serial.available() > 0)
   {
      String str = Serial.readStringUntil('\n');
      String fila = str.substring(0,2);
      String columna = str.substring(2,4);
      String pax = str.substring(4,6);
      String pay = str.substring(6,8);    
      long tamano = sizeof(str);
      //long tamano = strlen(str);
      int data = str.toInt();
      int f = fila.toInt();
      int c = columna.toInt();
      int x = pax.toInt();
      int y = pay.toInt();
      //DEBUG(data);
      Serial.print("numero: "); Serial.print(data); //Serial.println("A");
      Serial.print("longitud : "); Serial.print(tamano); //Serial.println("A");
      Serial.print("fila: "); Serial.print(f); //Serial.println("A");
      Serial.print("columna: "); Serial.print(c); //Serial.println("A");
      Serial.print("coordenada x: "); Serial.print(x); //Serial.println("A");
      Serial.print("coordenada y: "); Serial.print(y); //Serial.println("A");
      Serial.println("");
      //invento Se puede comentar

   }
}
