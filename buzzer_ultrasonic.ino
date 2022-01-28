#define trigpin 12
#define echopin 11
#define buzzer 2

int safetydistance=10;

int ultrasonic()
{
  digitalWrite(trigpin,LOW);
  delay(2);

  digitalWrite(trigpin,HIGH);
  delay(10);
  digitalWrite(trigpin,LOW);

  long duration=pulseIn(echopin,HIGH);

  int distance=duration*0.034/2;
  return distance;
}
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int dist=ultrasonic();
  if(dist<=safetydistance)
  {
    tone(buzzer,500);
  }
  else
  {
    noTone(buzzer);
  }
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(100);
  
}
