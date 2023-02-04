#define sensor_pin_soil 39
void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin_soil, INPUT);
  Serial.println("Reading");
  delay(2000);
}
void loop()
{
  int value_soil= analogRead(sensor_pin_soil);
  value_soil = map(value_soil,4095,990,0,100);
  Serial.print("Soil : ");
  Serial.print(value_soil);
  Serial.println("%");
  delay(1000);
}
