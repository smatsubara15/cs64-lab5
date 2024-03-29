#include "DecodeCode.h"
#include <stdio.h>
#include <math.h>
int power(int v, int exponent){
  int temp=1;
  for(int i=0;i<exponent;i++){
    temp=temp*v;
  }
  return temp;
}

int unsignedBits(int v, int start, int finish){
  v=v>>start;
  int range=(finish-start)+1;
  range=power(2,range);
  range=range-1;
  v=v&range;
  return v;
}

int signedBits(int v, int start, int finish){
  v=v>>start;
  int x=v;
  int signCheck=power(2,finish-start);
  x=x&signCheck;

  int range=(finish-start)+1;
  range=power(2,range);
  range=range-1;
  
  if(x==0){
    v=v&range;
    return v;
  }
  else{
    v=(~v)+1;
    v=v&range;
    v=v*-1;
    return v;
  }
}
  
mipsinstruction decode(int value)
{
	mipsinstruction instr;

	// TODO: fill in the fields
	instr.funct = unsignedBits(value,0,5);
	instr.immediate = signedBits(value,0,15);
	instr.rd = unsignedBits(value,11,15);
	instr.rt = unsignedBits(value,16,20);
	instr.rs = unsignedBits(value,21,25);
	instr.opcode = unsignedBits(value,26,31);

	return instr;
}


