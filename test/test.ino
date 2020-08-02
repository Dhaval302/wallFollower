int trig1 = 3;
  int echo1 = 5;
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
}

long dist(){
  long dur;
  digitalWrite(trig1, LOW);
  delayMicroseconds(5); // delays are required for a succesful sensor operation.
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trig1, LOW);
  dur = pulseIn(echo1, HIGH);
  return (dur/58);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = dist();
  if(distance<5){
    Serial.println(" distance less than 5");
  }else{
    Serial.println(" distance more than 5");
  }
}
