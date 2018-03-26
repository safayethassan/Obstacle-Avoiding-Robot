const int TrigLeft = 12;
const int EchoLeft = 13;
const int TrigFront = 8;
const int EchoFront = 9;
int LeftMotorForward = 2;
int LeftMotorReverse = 3;
int RightMotorForward = 4;
int RightMotorReverse = 5;
long durationleft,durationfront,cmleft, cmfront, firstTime = 0;
void setup() {
pinMode(TrigLeft, OUTPUT);
pinMode(EchoLeft, INPUT);
pinMode(TrigFront, OUTPUT);
pinMode(EchoFront, INPUT);
pinMode(RightMotorForward, OUTPUT);
pinMode(RightMotorReverse, OUTPUT);
pinMode(LeftMotorForward, OUTPUT);
pinMode(LeftMotorReverse, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clear the trigPins
digitalWrite(TrigLeft, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TrigLeft, HIGH);
delayMicroseconds(5);
digitalWrite(TrigLeft, LOW);
// Reads the echoPin, returns the sound wave travel time in
microseconds
durationleft = pulseIn(EchoLeft, HIGH);
cmleft = durationleft / 29 / 2;//converts the time duration to cm
digitalWrite(TrigFront, LOW);
delayMicroseconds(2);
digitalWrite(TrigFront, HIGH);
delayMicroseconds(5);
digitalWrite(TrigFront, LOW);
durationfront = pulseIn(EchoFront, HIGH);
cmfront = durationfront / 29 / 2;//converts the time duration to cm
// Prints the distance on the Serial Monitor
Serial.print("left: ");
Serial.println(cmleft);
Serial.print("front: ");
Serial.println(cmfront);
if(firstTime == 0){
if(cmleft > 20 && cmfront > 20){
turn(4);
firstTime=1;
delay(550);
}
}
if(cmleft < 30)
{
if(cmfront < 30)
{
turn(6);
delay(650);
turn(0);
delay(400);
} else {
turn(2);
delay(500);
//turn(0);
//delay(80);
}
}
else
{
if(cmfront < 30)
{
turn(6);
delay(650);
turn(0);
delay(400);
}
else {
turn(2);
delay(70);
}
}
}
void turn(int d){
if(d == 4) // Left Turn
{
digitalWrite(RightMotorForward, HIGH);
digitalWrite(RightMotorReverse, LOW);
digitalWrite(LeftMotorForward, LOW);
digitalWrite(LeftMotorReverse, LOW);
}
else if(d == 2) // Forward
{
digitalWrite(RightMotorForward, HIGH);
digitalWrite(LeftMotorForward, HIGH);
digitalWrite(RightMotorReverse, LOW);
digitalWrite(LeftMotorReverse, LOW);
}
else if(d == 6) // Right turn
{
digitalWrite(LeftMotorForward, HIGH);
digitalWrite(LeftMotorReverse, LOW);
digitalWrite(RightMotorForward, LOW);
digitalWrite(RightMotorReverse, LOW);
}
else if(d == 0) // Back turn
{
digitalWrite(LeftMotorForward, LOW);
digitalWrite(LeftMotorReverse, HIGH);
digitalWrite(RightMotorForward, LOW);
digitalWrite(RightMotorReverse, HIGH);
}
}