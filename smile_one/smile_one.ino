
//Constants:

const int ledPin = 0;   //pin 3 has PWM funtion
const int ledPin2 = 1;
const int ledPin3 = 2;
const int ledPin4 = 3;
const int ledPin5 = 4;

const int flexPin = A0; //pin A0 to read analog input
const int flexPin2 = A1; 
const int flexPin3 = A2; 
const int flexPin4 = A3; 
const int flexPin5 = A4; 

//Variables:
int value; //save analog value

void setup(){
  pinMode(ledPin, OUTPUT);  //Set pin 3 as 'output'
  Serial.begin(9600);       //Begin serial communication
}

void loop(){
  value = analogRead(flexPin);         //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin, value);          //Send PWM value to led
  delay(100);                          //Small delay

  value = analogRead(flexPin2);         //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin2, value);          //Send PWM value to led
  delay(100);                          //Small delay

  value = analogRead(flexPin3);         //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin3, value);          //Send PWM value to led
  delay(100);                          //Small delay

  value = analogRead(flexPin4);         //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin4, value);          //Send PWM value to led
  delay(100);                          //Small delay

  value = analogRead(flexPin5);         //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin5, value);          //Send PWM value to led
  delay(100);                          //Small delay
  
}
