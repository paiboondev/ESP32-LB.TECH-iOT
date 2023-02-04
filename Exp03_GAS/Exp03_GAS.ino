#define sensor_pin_gas 35
void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin_gas, INPUT);
  Serial.println("Reading");
  delay(2000);
}
void loop()
{
  int value_gas= analogRead(sensor_pin_gas);
  value_gas = map(value_gas,1500,4095,0,100);
  Serial.print("Gas : ");
  Serial.print(value_gas);
  Serial.println("%");
  delay(1000);
}
