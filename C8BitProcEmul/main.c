#include <stdio.h>
#include "Register.h"
#include "ALU.h"

int main()
{
    REG REG0;
    REG REG1;
    unsigned char out;
    unsigned char COUT;
    
    unsigned char prog[10] = {0};
    short com;
    unsigned char val0;
    unsigned char val1;
    
    val0 = 40;
    val1 = 128;
    
    printf("val0 = %u\nval1 = %u\n", val0, val1);
    
    while(1){
        scanf("%hd", &com);
        if(com == -1){
            return 0;   
        }
        ALU(com, val0, val1, &out);
        printf("%u\n", NEG(val1));
        printf("out = %u\n", out);
    }
    
    return 0;
}
