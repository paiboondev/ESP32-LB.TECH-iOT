#define sensor_pin_soil 39
#define led_red 25
#define led_green 26
#define relay01 32
void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin_soil, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(relay01, OUTPUT);
  digitalWrite(led_red,HIGH);
  digitalWrite(led_green,HIGH);
  digitalWrite(relay01,HIGH);
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
  if(value_soil<=20){
    digitalWrite(led_red,LOW);
    digitalWrite(led_green,HIGH);
    digitalWrite(relay01,LOW);
  }
  else{
    digitalWrite(led_red,HIGH);
    digitalWrite(led_green,LOW);
    digitalWrite(relay01,HIGH);
  }
  delay(1000);
}
