#include <stdbool.h>
#include <stdio.h>

typedef enum{
  PSH,
  ADD,
  POP,
  SET,
  HLT
} InstructionSet;

typedef enum {
	A, B, C, D, E, F, IP, SP, NUM_OF_REGISTERS
} Registers;

int registers [NUM_OF_REGISTERS];

void print_register(int reg){
	printf("%d\n", registers[reg]);
}

const int program[] = {
  PSH, 5,
  PSH, 6,
  ADD,
  POP,
  HLT
};

#define sp (registers[SP])
#define ip (registers[IP])

int stack[256];
bool running = true;

int fetch(){
return program[ip];
}

void eval(int instr){
	switch(instr){
	 case HLT: running = false; break;
	 case PSH: {
		sp++; 
		stack[sp] = program[++ip]; 
		break;
		}
	 case POP: {
		int val_popped= stack[sp--];
		printf("popped %d\n", val_popped);
		break;
		}
	 case ADD: {
		int a = stack[sp--];
		int b = stack[sp--];
		int result = a + b;
		sp++;
		stack[sp] = result;
		break;	
		} 
}
}


int main(){
  while(running){
	
	eval(fetch());
	ip++;
}
  return 0;
}
