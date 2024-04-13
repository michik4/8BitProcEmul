#ifndef REG_H
#define REG_H 

typedef struct Register REG;

struct Register{
  unsigned SAVE : 1;
  unsigned LOAD : 1;
  unsigned VAR;
};

/*save*/
#define IN_ON(REG){REG.SAVE=1;} 
#define IN_OFF(REG){REG.SAVE=0;}
#define SAVE(REG, value){if(REG.SAVE == 1){REG.VAR = value;}}
/*load*/
#define OUT_ON(REG){REG.LOAD=1;}
#define OUT_OFF(REG){REG.LOAD=0;}
#define LOAD(out, REG){if(REG.LOAD == 1){out = REG.VAR;}else{out = 0;}}
#define XLOAD(out, REG){out = REG.VAR;}

#endif