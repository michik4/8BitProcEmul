#include "bit.h"
#include <stdio.h>

void bitdec(unsigned val){
    short nbit = 7;
    for(nbit; nbit >= 0; nbit--){
        if(val & (1 << nbit)){
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}