// Online C compiler to run C program online


    #include <stdio.h>

    int main() {
    // Write C code here
    unsigned char num ;                             //input number
    unsigned char A=0x00,B=0x00,C=0x00;	    //binary inputs
    unsigned char one = 0x01;
    unsigned char out,out_canonical, Nor;                         //outputs

    printf("A B C  (B+C')(A'+B)  canonical POS Form\n");

    for (num = 0x00; num<0x08; num++)               //loop to iterate through all usecases
    {
        A = num>>2;    B = num>>1;    C = num>>0; //changing the inputs

        out = (B|(~C))&((~A)|B);//Original Boolean Function
        out_canonical=(A|B|(~C))&((~A)|B|(C))&((~A)|B|(~C));//canonical POS form


        printf("%x %x %x", one&A, one&B, one&C);    //Input ABC
        printf("\t\t%x\t\t\t%x\n" , one&out, one&out_canonical);     //outouts

    }

    return 0;


}

