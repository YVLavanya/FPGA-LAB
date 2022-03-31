#include <Arduino.h>
#define A 2
#define B 3
#define C 4
int a,b,c,f1,f2;
int n=13;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  // put your setup code here, to run once:
}

void loop() {
        a=digitalRead(A);
        b=digitalRead(B);
        c=digitalRead(C);
        f1=(b||(!c))&&((!a)||b);
        f2=(a||b||(!c))&&((!a)||b||c)&&((!a)||b||(!c));
                if((f1==1)&&(f2==1))
                digitalWrite(LED_BUILTIN,HIGH);
                else
                digitalWrite(LED_BUILTIN,LOW);
  // put your main code here, to run repeatedly:
}
