#define mrl 6
#define mr2 5
#define ml1 9
#define ml2 10
#define servo 7
#define triger 8

#include <Servo.h>
int distance;
Servo myservo; 
void setup() 
{
Serial.begin(9600);
myservo.attach(7):
for (int i=0 ; 1<11 : 1++)

{
pinMode (1, OUTPUT);
}
}

int getDistance ()
{
int distance;
unsigned long pulseduration = 0;
pinMode (triger, OUTPUT);
digitalWrite(triger,LOW);
delayMicroseconds (5);
digitalWrite(triger, HIGH);
delayMicroseconds(5); 
digitalWrite(triger, LOW);
pinMode (triger, INPUT);
pulseduration = pulseln (triger, HIGH);
pulseduration = pulseduration/2; 
distance = int (pulseduration/29);
return distance;
}

void goForward()
{
    digitalWrite(mr1, HIGH);
    digitalWrite(mr2, LOW);
    digitalWrite(ml1,HIGH);
    digitalWrite(ml2,LOW);
}

void goBackward()
{
    digitalWrite(mr1, LOW);
    digitalWrite(mr2, HIGH);
    digitalWrite(ml1,LOW);
    digitalWrite(ml2,HIGH);
}

void turnLeft()
{
    digitalWrite(mr1, HIGH);
    digitalWrite(mr2, LOW);
    digitalWrite(ml1,LOW);
    digitalWrite(ml2,HIGH);
}

void turnRight()
{
    digitalWrite(mr1, LOW);
    digitalWrite(mr2, HIGH);
    digitalWrite(ml1,HIGH);
    digitalWrite(ml2,LOW);
}

void STOP()
{
    digitalWrite(mr1, LOW);
    digitalWrite(mr2, LOW);
    digitalWrite(ml1,LOW);
    digitalWrite(ml2,LOW);
}

void loop()
{
    Serial.print(distance);
    myservo.write(90);
    delay(15);
    distance = int (getDistance());
    Serial.print(distance);

    while(distance>= 20){
        goForward();
        distance=getDistance();
    }

    while(distance <= 20){
        STOP();
        delay(1000);
        distance=getDistance();
    }

    myservo.write(90);
    switch(select){
        case 0;
        turnLeft();
        delay(250);
        STOP();
        break;
        case 45;
        turnleft();
        delay(500);
        STOP();
        break;
        case 135;
        turnRight();
        delay(250);
        STOP();
        break;
        case 180;
        turnRight();
        delay(500);
        STOP();
        break;
    }

}
