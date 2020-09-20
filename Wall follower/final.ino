const int trig1 = A0;//forward
const int echo1 = A1;
const int trig2 = A2;//right
const int echo2 = A3;
const int trig3 = A4;
const int echo3 = A5;

const int in1 = 9;
const int in2 = 10;
const int in3 = 5;
const int in4 = 6;

const int enA = 11;
const int enB = 3;

//#define PWM 10;
int PWM = 100;
int DIS = 5;
//#define DIS 20;

 
long FrontSensor(){
  Serial.println("forward ultra sonic sensor found..");
  long dur;
  digitalWrite(trig1, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trig1, HIGH);
  delayMicroseconds(20); //this delay is required as well!
  digitalWrite(trig1, LOW);
  dur = pulseIn(echo1, HIGH);
  return (dur/58);
 
}
long RightSensor(){
    Serial.println("right ultra sonic sensor found..");

  long dur;
  digitalWrite(trig2, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trig2, HIGH);
  delayMicroseconds(20); //this delay is required as well!
  digitalWrite(trig2, LOW);
  dur = pulseIn(echo2, HIGH);
  return (dur/58);
 
}

long LeftSensor(){

    Serial.println("left ultra sonic sensor found..");

  long dur;
  digitalWrite(trig3, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trig3, HIGH);
  delayMicroseconds(20); //this delay is required as well!
  digitalWrite(trig3, LOW);
  dur = pulseIn(echo3, HIGH);
  return (dur/58);
 
}

void forward (){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM);  
  analogWrite(enB, PWM);
}

void left_turn (){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void right_turn (){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void  back(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

/*void back(){
  //right
  long right2 = RightSensor();
  long left2 = LeftSensor();
  long front2 = FrontSensor();
  if(right2>left2)
  {
  while(front2<DIS){
    turn_right();
    delay(100);
  }
 
  }
  else
  {
  while(front2<DIS){
    turn_left();
    delay(100);
  }
 }
forward();
}*/
void stop (){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA,0 );
  analogWrite(enB,0 );
}
void setup(){
Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);

  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
 
 stop();
}

void loop() {
  // put your main code here, to run repeatedly:

  long front = FrontSensor();
  delay(10);
  long right = RightSensor();
  delay(10);
  long left = LeftSensor();
 delay(10);
 if(front<DIS)
 {
  if(right>left)
  {
    if((right<DIS)&&(left<DIS))
    {
      stop();
      //delay(200);
      back();
      //delay(1000);
    }
    else
    {
      right_turn();
      //delay(500);
    }
     
  }
  else if(right<left)
  {
    if((right<DIS)&&(left<DIS))
    {
      stop();
      //delay(200);
      back();
      //delay(1000);
    }
    else
    {
      left_turn();
      //delay(500);
    }
  }
 }
 else if(right<DIS)
 {
  left_turn();
  //delay(500);
 }
 else if(left<DIS)
 {
  right_turn();
  delay(500);
 }
 else
 forward();
}
 /* if(front<DIS && right<DIS && left<DIS)
  {
      u_turn();
  }
 
 if(front<DIS && right<DIS && left>DIS){
      turn_left();
  }
 else if(front<DIS && right>DIS && left<DIS){
     
      turn_right();
  }
 else if(front<DIS && right>DIS && left>DIS){
      //priority set here
      turn_right();
  }
 else if(front>DIS && right>DIS && left<DIS)
    {
        turn_right();
        delay(100);
        forward();
    }
 else  if(front>DIS && right<DIS && left>DIS){
       turn_left();
       delay(100);
       forward();
   }
   else{
        forward();    
   }*/