#include <stdio.h>
#include "Register.h"
#include "ALU.h"

int main()
{
    REG REG0;
    REG REG1;
    unsigned out;
    unsigned COUT;
    
    unsigned prog[10] = {0};
    short com;
    unsigned val0;
    unsigned val1;
    
    val0 = 113;
    val1 = 128;
    
    printf("val0 = %u\nval1 = %u\n", val0, val1);
    
    while(1){
        scanf("%hd", &com);
        if(com == -1){
            return 0;   
        }
        ALU(com, val0, val1, &out);
    }
    printf("out = %u", out);
    
    
    return 0;
}
