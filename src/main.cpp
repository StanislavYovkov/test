#include <Arduino.h>

#include <NewPing.h>
 
#define TRIG   A0
#define ECHO  A1
#define MAX_DIST 200

#define TRIG_L   A4
#define ECHO_L  A5
#define MAX_DIST_L 200

#define TRIG_R   A2
#define ECHO_R  A3
#define MAX_DIST_R 200

unsigned int distance ;
unsigned int distance_L ;
unsigned int distance_R ;

 int Right_PWM=9;
 int RightForward =5;
 int RightBackward =4;
 int LeftForward =8;
 int LeftBackward =7;
 int Left_PWM=10;

// NewPing setup of pins and maximum distance
NewPing sonar_R(TRIG_R, ECHO_R, MAX_DIST_R);
NewPing sonar_L(TRIG_L, ECHO_L, MAX_DIST_L);
NewPing sonar(TRIG, ECHO, MAX_DIST);

void Forward();
void Backward();
void Left();
void Turn();
void TurnLeft();
void Right();
void Stop();


void setup() {
  
   pinMode(6,OUTPUT);
   pinMode(RightForward, OUTPUT);
   pinMode(RightBackward, OUTPUT);
   pinMode(Right_PWM, OUTPUT);
   pinMode(LeftForward, OUTPUT);  
   pinMode(LeftBackward, OUTPUT);
   pinMode(Left_PWM, OUTPUT);
 
 digitalWrite(6,HIGH);
 unsigned int distance = sonar.ping_cm();  
 unsigned int distance_L = sonar_L.ping_cm();  
 unsigned int distance_R = sonar_R.ping_cm();  
 Serial.begin(9600);
 
    Forward();  
}

/*-------------------------------------------------*/

  
void loop() {
 
  distance_R = sonar_R.ping_cm(); 
  if (distance_R == 0 ) distance_R =255;

    distance = sonar.ping_cm();
    if (distance == 0 ) distance =255;
 
     distance_L = sonar_L.ping_cm(); 
 if (distance_L == 0 ) distance_L =255;

     
    if (distance_R > 15 && distance >15  ) {
 Forward();
 analogWrite(Right_PWM,150);
  analogWrite(Left_PWM,45);
   delay(100);}
   
    else if(distance_R < 15 && distance >15){
  Forward();
 analogWrite(Right_PWM,110);
  analogWrite(Left_PWM,170);
   delay(75);    }
 
 else if(distance <15/* && distance_R <15*/ )    {
   Backward();   
   delay(150);
   TurnLeft();
   delay(200);
    }  
 
}

void Forward(){
  digitalWrite(RightForward,1); 
  digitalWrite(RightBackward,0);   
  digitalWrite(LeftForward,1); 
  digitalWrite(LeftBackward,0);
 
}

void Backward(){
  digitalWrite(RightForward,0); 
  digitalWrite(RightBackward,1); 
  digitalWrite(LeftForward,0); 
  digitalWrite(LeftBackward,1);
  analogWrite(Right_PWM,80);
  analogWrite(Left_PWM,80);
}

void Left(){
  digitalWrite(RightForward,0);
  digitalWrite(RightBackward,1);
  digitalWrite(LeftForward,1);  
  digitalWrite(LeftBackward,0);
  analogWrite(Right_PWM,90);
  analogWrite(Left_PWM,20);
}

void Turn(){
  digitalWrite(RightForward,0);
  digitalWrite(RightBackward,1);
  digitalWrite(LeftForward,1);  
  digitalWrite(LeftBackward,0);
}

void TurnLeft(){
  digitalWrite(RightForward,0);
  digitalWrite(RightBackward,1);
  digitalWrite(LeftForward,1);  
  digitalWrite(LeftBackward,0);
  analogWrite(Right_PWM,220);
  analogWrite(Left_PWM,220 );
}

void Right(){
  digitalWrite(RightForward,1);
  digitalWrite(RightBackward,0);
  digitalWrite(LeftForward,0);  
  digitalWrite(LeftBackward,1);
  analogWrite(Right_PWM,20);
  analogWrite(Left_PWM,90);
}

void Stop(){
  digitalWrite(RightForward,0);
  digitalWrite(LeftForward,0);
  digitalWrite(RightBackward,0);
  digitalWrite(LeftBackward,0);
}
