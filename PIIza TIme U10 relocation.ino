
int brightness = 0;
int fadeAmount = 5;
int voltDiv = 0;

void setup() 
{
pinMode(1, OUTPUT);
pinMode(A0, INPUT);
pinMode(2, INPUT);

}

void loop()
{
voltDiv = analogRead(A0); 

if(voltDiv <= 540)
{
  analogWrite(1, 200);
}

if(voltDiv > 540)
{
  digitalWrite(1, LOW);
}

if(digitalRead(2) == HIGH)
{
  analogWrite(1, brightness);
  brightness = brightness + fadeAmount;
  
  if(brightness <= 0 || brightness >= 255)
  {
    fadeAmount = -fadeAmount;
  }
  delay(30);
}
}
