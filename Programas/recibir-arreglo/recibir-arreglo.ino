const size_t dataLength = 10;
int data[dataLength];
int dataIndex = 0;
 
void setup()
{
  Serial.begin(9600);
} 
 
 
void loop()
{   
  if(Serial.available() >= sizeof(data[0]))
  {
    byte byte1 = Serial.read();
    byte byte2 = Serial.read();
    data[dataIndex] = byteToInt(byte1, byte2);
 
    dataIndex++;
    if(dataIndex >= dataLength)
    {
      dataIndex = 0;
    }
  } 
} 
 
uint16_t byteToInt(byte byte1, byte byte2)
{
   return (uint16_t)byte1 << 8 | (uint16_t)byte2;
}
