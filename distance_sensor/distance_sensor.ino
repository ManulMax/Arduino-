#include <TM1637Display.h>
#define CLK 6
#define DIO 3
TM1637Display display(CLK, DIO);
int ledr=4;
int ledb=3;
int ledw=6;
int buzz=5;
int trig=11;
int echo=12;
int duration , distance ;

void setup() {
pinMode(ledr , OUTPUT);
pinMode(ledb , OUTPUT);
pinMode(ledw , OUTPUT);
pinMode(buzz , OUTPUT);
pinMode(trig , OUTPUT);
pinMode(echo , INPUT);

Serial.begin(9600);
display.setBrightness(0, true);
}

void loop() {
 digitalWrite(trig , LOW);
 delay(20);
 digitalWrite(trig , HIGH);
 delay(100);
 digitalWrite(trig , LOW);

 duration = pulseIn(echo , HIGH);
 distance = duration*0.034/2;
 Serial.println(distance);

 int digit1=distance/100;
 int digit2=distance/10;
 int digit3=distance/1;

display.showNumberDec(digit1 , false);
display.showNumberDec(digit2 , false);
display.showNumberDec(digit3 , false);

if(distance > 150){digitalWrite(ledw ,HIGH);
                  digitalWrite(ledb , LOW);
                  digitalWrite(ledr , LOW);
                  digitalWrite(buzz , LOW);
}

if(distance < 150){digitalWrite(ledw ,LOW);
                  digitalWrite(ledb , HIGH);
                  digitalWrite(ledr , LOW);
                  digitalWrite(buzz , LOW);
}

 if (distance <50)
     {digitalWrite(ledb , LOW);
      digitalWrite(ledw , LOW);
      digitalWrite(ledr ,HIGH);
      delay(20);
      digitalWrite(ledr ,LOW);
      digitalWrite(buzz ,HIGH);
      delay(50);
      digitalWrite(buzz , LOW);
    }
 if(distance <5){digitalWrite(buzz ,HIGH);}   
 delay(100);
}
