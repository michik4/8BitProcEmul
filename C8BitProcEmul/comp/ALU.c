#include "ALU.h"
#include <stdio.h>
#include "bit.h"
#include "type.h"

/*1 bit ADDer
    CIN -> Carry in
    COUT -> Carry out
*/
unsigned8_t ADD1(unsigned8_t A, unsigned8_t B, unsigned8_t CIN, unsigned8_t * COUT){
    *COUT = ((A & B) | (A & CIN) | (B & CIN));
    return (A ^ B) ^ CIN;
}
void ADD8(unsigned8_t val0, unsigned8_t val1, unsigned8_t *out){
    unsigned8_t CIN = 0;
    unsigned8_t COUT;
    unsigned8_t buf;
    
    for(short nbit = 7; nbit >= 0; nbit--){
        if(ADD1((val0&(1<<nbit)), (val1&(1<<nbit)), CIN, &COUT)){
            *out |= (1<<nbit);
        }else{
            *out &= ~(1<<nbit);
        }
        COUT = CIN;
    }
}

unsigned8_t NEG(unsigned8_t val){
    unsigned8_t out;
    ADD8(1, ~(val), &out);
    return out;
}
void SUB8(unsigned8_t val0, unsigned8_t val1, unsigned8_t* out){
    ADD8(val0, NEG(val1), out);
}

void ALU(unsigned8_t OP_CODE, unsigned8_t const val0, unsigned8_t const val1, unsigned8_t* out){
    OP_CODE &= 7; /*7 = 0000 0111 */
    printf("%u\n", OP_CODE);
    switch (OP_CODE)
    {
    case(0):
        OR(val0, val1, out);
        break;
    case(1):
        NAND(val0, val1, out);
        break;
    case(2):
        NOR(val0, val1, out);
        break;
    case(3):
        AND(val0, val1, out);
        break;
    case(4):
        ADD8(val0, val1, out);
        break;
    case(5):
        SUB8(val0, val1, out); /*not correctly work in NEG (negative)*/
        break;
    default:
        break;
    }
}