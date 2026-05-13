
int ENA = 14; //top right motor
int IN1 = 16; //top right motor
int IN2 = 15; //top right motor
int ENB = 19; //top left motor
int IN3 = 17; //top left motor
int IN4 = 18; //top left motor
int IN5 = 3;  //bottom right motor
int IN6 = 4;  //bottom right motor
int ENC = 5;  //bottom right motor
int IN8 = 2;  //bottom left motor
int IN7 = 13; //bottom left motor
int END = 12; //bottom left motor

int Trig = 10;
int Echo = 9;

int Distance;
long Duration;

int motorSpeed = 200; // Speed (0–255)




void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  Serial.begin(9600);
}


void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENC, motorSpeed);
  analogWrite(END, motorSpeed);
}




void reverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENC, motorSpeed);
  analogWrite(END, motorSpeed);}




void stop() {
// Stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}


void loop() {
 // put your main code here, to run repeatedly:
 digitalWrite(Trig, LOW);
 delayMicroseconds(2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(Trig, LOW);
 Duration = pulseIn(Echo, HIGH);
 Distance = (343*Duration*100)/2000000;
 Serial.println(Distance);
 if(Distance < 40){
  stop();
 }
 else{
  forward();
 }
 delay(500);

}






