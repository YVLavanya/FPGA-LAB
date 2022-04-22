#include <avr/io.h>
#include <util/delay.h>

 
int main (void)
{
	int i,z,x,y,out1;
 DDRD   |= 0b00000000;
 DDRB   |= ((1 << DDB5));
 
  while (1) {

     i = PIND;
            
     x= i & 0b00100000;
     y= i & 0b01000000;
     z= i & 0b10000000;
     out1=(y || !z)&&(!x ||y);
/*     out2=(x || y || !z) && (!x || y || !z) ;*/
if(out1==0)
PORTB = ((0<<  PB5));
else
PORTB = ((1 <<  PB5));

  }

  /* . */
  return 0;

}

