#define sensor_pin_gas 35
#define led_red 25
#define led_green 26
#define relay01 32
void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin_gas, INPUT);
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
  int value_gas= analogRead(sensor_pin_gas);
  value_gas = map(value_gas,1500,4095,0,100);
  Serial.print("Gas : ");
  Serial.print(value_gas);
  Serial.println("%");
  if(value_gas>=60){
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
