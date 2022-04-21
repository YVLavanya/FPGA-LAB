.include "m328Pdef.inc"

Start:
        ldi r17, 0b11100011 ; identifying input pins 2,3,4
        out DDRD,r17                ; declaring pins as input                 
	ldi r17, 0b11111111
	out PORTD,r17
        in r17,PIND
        
        ldi r20,0b00000010
        rcall loopr
        
        ldi r21,0b00000001
        and r21,r17 ;a
        lsr r17
        ldi r22,0b00000001
        and r22,r17 ;b
        lsr r17
        ldi r23,0b00000001
        and r23,r17 ;c
    

        ldi r25,0b00000001
        ldi r26,0b00000001
        ldi r27,0b00000001

        and r25,r21     ;a
        and r26,r22     ;b
        and r27,r23     ;c
       ldi r28,0b00000001
        eor r28,r27     ;(c)'(25)y1
        or r28,r26    ;b+c'
        
        ldi r29,0b00000001
        eor r29,r25     ;a'
        or  r29,r26     ;a'+b

        and r29,r28     ;(a'+b)(b+c')
        

        ldi r20,0b00000101
        rcall loopl

        ldi r16, 0b00100000 ;identifying output pin 13 of arduino
        out DDRB,r16                ;declaring pins as output
        out PORTB,r29                ;

        rjmp Start

loopr:        lsr r17
        dec r20
        brne loopr
        ret

loopl:        lsl r29
        dec r20
        brne loopl
        ret
