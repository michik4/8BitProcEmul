#ifndef ALU_H
#define ALU_H

#define OR(val0, val1, out) {*out = val0 | val1;};
#define NAND(val0, val1, out) {*out = ~(val0 & val1);};
#define NOR(val0, val1, out) {*out = val0 ^ val1;};
#define AND(val0, val1, out) {*out = val0 & val1;};

#define SUB(val0, val1, out) {*out = val0 | val1;};

unsigned NEG(unsigned val);
void ADD8(unsigned val0, unsigned val1, unsigned *out);
unsigned ADD1(unsigned val0, unsigned val1, unsigned CIN, unsigned* COUT);
void ALU(unsigned OP_CODE, unsigned val0, unsigned val1, unsigned* out);

#endif