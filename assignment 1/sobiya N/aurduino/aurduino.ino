int sensor=4, trig=2, echo=2, light=8, buzz=12;
int dist = 0;

long objectDistance(int a, int b)
{
  pinMode(a, OUTPUT); 
  digitalWrite(a, LOW);
  delayMicroseconds(2);
  digitalWrite(a, HIGH);
  delayMicroseconds(10);
  digitalWrite(a, LOW);
  
  pinMode(b, INPUT);
 
  return pulseIn(b, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(light, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(light, LOW);
}

void loop()
{
  //readUltrasonicDistance(7, 7)
  dist = 0.01723 * objectDistance(trig, echo);
  Serial.print("Distance is ");
  Serial.print(dist);
  Serial.println("cm");
  if(dist>50 && dist<100)
  {
    tone(buzz, 50);
    delay(2000);
    noTone(buzz);
    //delay(1000);
    if(digitalRead(sensor))
    {
      digitalWrite(light, HIGH);
      delay(2000);
    }
  }
}
