
const  byte data[] = {0, 50, 100, 150, 200, 250};
const size_t dataLength =6;// sizeof(data) / sizeof(data[0]);
void setup() {
  Serial.begin(9600);
  Serial.write(data, dataLength);

}

void loop() {
  Serial.write(data, dataLength);
  delay(5000);

}
