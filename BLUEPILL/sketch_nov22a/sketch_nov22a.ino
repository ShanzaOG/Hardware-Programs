#define led_pin PB12
void setup() {
  pinMode(led_pin,OUTPUT);// put your setup code here, to run once:

}

void loop() {

  digitalWrite(led_pin,LOW);
  delay(1000);
  digitalWrite(led_pin,HIGH);
  delay(1000);
  //digitalWrite(LED_BUILTIN,LOW);
  //delay(3000);// put your main code here, to run repeatedly:

}
