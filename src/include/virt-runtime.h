#ifndef __VIRT_RUNTIME_H
#define __VIRT_RUNTIME_H

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

typedef void (*virt_inst_t)(virt_proc_t*);

extern virt_proc_t* current_proc;

#define INST_FOR_ALL(name) void name ## 8 (virt_proc_t*); \
	void name ## 16 (virt_proc_t*); \
	void name ## 32 (virt_proc_t*); \
	void name ## 64 (virt_proc_t*);

INST_FOR_ALL(add)
INST_FOR_ALL(sub)
INST_FOR_ALL(mul)
INST_FOR_ALL(div)

long int virt_pop(virt_proc_t* proc);
void virt_push(virt_proc_t* proc, long int value);

#endif
