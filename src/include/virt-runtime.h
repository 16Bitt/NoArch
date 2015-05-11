#ifndef __VIRT_RUNTIME_H
#define __VIRT_RUNTIME_H

//This is the basic memory structure for a FORTH process
typedef struct{
	//Registers
	unsigned int ip;
	unsigned int sp;
	unsigned int rsp;

	//Memory regions
	long int* mem;
	long int* stack;
	long int* rstack;
} virt_proc_t;

//This is the datatype for FORTH words (instructions)
typedef void (*virt_inst_t)(virt_proc_t*);

extern virt_proc_t* current_proc;	//Currently executing process
extern void* inst_list;			//List of names and virt_inst_t's

//Generates a function definition for each word type (8 - 64 bits, for now)
#define INST_FOR_ALL(name) void virt_ ## name ## 8 (virt_proc_t*); \
	void virt_ ## name ## 16 (virt_proc_t*); \
	void virt_ ## name ## 32 (virt_proc_t*); \
	void virt_ ## name ## 64 (virt_proc_t*);

//Generate common instructions for all word sizes
INST_FOR_ALL(add)
INST_FOR_ALL(sub)
INST_FOR_ALL(mul)
INST_FOR_ALL(div)
INST_FOR_ALL(lit)
INST_FOR_ALL(peek)
INST_FOR_ALL(poke)
INST_FOR_ALL(cmp)

//Flow control
void jmp(virt_proc_t* proc);
void call(virt_proc_t* proc);
void ret(virt_proc_t* proc);

//Uses inst_list to find a function
virt_inst_t inst_lookup(char* name);

//Push and pop long values to and from a process
long int virt_pop(virt_proc_t* proc);
void virt_push(virt_proc_t* proc, long int value);

#endif
