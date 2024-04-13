#include "ALU.h"
#include <stdio.h>
#include "bit.h"

unsigned ADD1(unsigned A, unsigned B, unsigned CIN, unsigned * COUT){
    *COUT = ((A & B) | (A & CIN) | (B & CIN));
    return (A ^ B) ^ CIN;
}
void ADD8(unsigned val0, unsigned val1, unsigned *out){
    unsigned CIN = 0;
    unsigned COUT;
    unsigned buf;
    
    for(short nbit = 7; nbit >= 0; nbit--){
        if(ADD1((val0&(1<<nbit)), (val1&(1<<nbit)), CIN, &COUT)){
            *out |= (1<<nbit);
        }else{
            *out &= ~(1<<nbit);
        }
        COUT = CIN;
    }
}

unsigned NEG(unsigned val){
    unsigned out;
    ADD8(1, ~(val), &out);
    return out;
}
void SUB8(unsigned val0, unsigned val1, unsigned* out){
    ADD8(val0, NEG(val1), out);
}

void ALU(unsigned OP_CODE, unsigned val0, unsigned val1, unsigned* out){
    bitdec(OP_CODE);
    if((OP_CODE & (0)) && (OP_CODE & (0 << 1)) && (OP_CODE & (0 << 2)))
    { 
        /*000 (0) OR*/
        printf("%s\n", "OR");
        OR(val0, val1, out);
        return;
    } 
    else if((OP_CODE & (1 << 0)) && (OP_CODE & (0 << 1)) && (OP_CODE & (0 << 2)))
    { 
        /*001 (1) NAND*/
        printf("%s\n", "NAND");
        NAND(val0, val1, out);
        return;
    }
    else if((OP_CODE & (0 << 0)) && (OP_CODE & (1 << 1)) && (OP_CODE & (0 << 2)))
    {
        /*010 (2) NOR*/
        printf("%s\n", "NOR");
        NOR(val0, val1, out);
        return;
    }
    else if(OP_CODE & (1 << 0) && OP_CODE & (1 << 1) && OP_CODE & (0 << 2))
    {
        /*011 (3) AND*/
        printf("%s\n", "AND");
        AND(val0, val1, out);
        return;
    }
    
    printf("%s\n", "opcode not found");
    return;
}