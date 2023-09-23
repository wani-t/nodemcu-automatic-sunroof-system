int motorPin1 = 15; // Blue - 28BYJ48 pin 1
int motorPin2 = 0; // Pink - 28BYJ48 pin 2
int motorPin3 = 14; // Yellow - 28BYJ48 pin 3
int motorPin4 = 12; // Orange - 28BYJ48 pin 4
 // Red - 28BYJ48 pin 5 (vcc)
int motorSpeed = 1; //variable to set stepper speed
int state=0;
void setup() {
//declare the motor pins as outputs
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
Serial.begin(9600);
}
void loop(){
 motorSpeed = 3;
 int sensorval= analogRead(A0); // get analog reading for ldr value
 float voltage = sensorval * (5.0/1023.0);
 Serial.println(voltage);
 delay(1000);
 // 90 deg demonstration calibrated for motor
 if(voltage>3.0 and state==0){
 for(int i = 0; i < 128; i++)
 clockwise(); //go the the cw rotation function
 Serial.println("opening sunroof");
 state=1;
 }
 //delay(2000);
 if(voltage<3.0 && state==1) {
 for(int i = 0; i <128; i++)
 counterclockwise(); //go the the ccw rotation function
 Serial.println("closing sunroof");
 state=0;
 }
 //delay(2000);
}
void counterclockwise (){
// 1
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(motorSpeed);
// 2
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, HIGH);
delay (motorSpeed);
// 3
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(motorSpeed);
// 4
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);
delay(motorSpeed);
// 5
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(motorSpeed);
// 6
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay (motorSpeed);
// 7
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);
delay(motorSpeed);
// 8
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
delay(motorSpeed);
}
//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 4 to 1
//delay "motorSpeed" between each pin setting (to determine speed)
void clockwise(){
// 1
digitalWrite(motorPin4, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, HIGH);
delay(motorSpeed);
// 2
digitalWrite(motorPin4, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, LOW);
delay(motorSpeed);
// 3
digitalWrite(motorPin4, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, LOW);
delay(motorSpeed);
// 4
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, LOW);
delay(motorSpeed);
// 5
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin1, LOW);
delay(motorSpeed);
// 6
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin1, LOW);
delay(motorSpeed);
// 7
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin1, HIGH);
delay(motorSpeed);
// 8
digitalWrite(motorPin4, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin1, HIGH);
delay(motorSpeed);
}
