#include "virt-text.h"
#include "virt-runtime.h"

void virt_instruction(virt_proc_t* proc){
	virt_inst_t inst = (virt_inst_t) proc->mem[proc->ip++];
	inst(proc);
}

long int virt_pop(virt_proc_t* proc){
	return proc->stack[proc->sp--];
}

void virt_push(virt_proc_t* proc, long int value){
	proc->stack[++proc->sp] = value;
}

#define INST_GENERATE(name, type, op) void virt_ ## name (virt_proc_t* proc){ \
	type n1 = (type) virt_pop(proc); \
	type n2 = (type) virt_pop(proc); \
	virt_push(proc, n2 op n1); \
}

INST_GENERATE(add8, char, +)
INST_GENERATE(add16, short, +)
INST_GENERATE(add32, int, +)
INST_GENERATE(add64, long int, +)

INST_GENERATE(sub8, char, -)
INST_GENERATE(sub16, short, -)
INST_GENERATE(sub32, int, -)
INST_GENERATE(sub64, long int, -)

INST_GENERATE(mul8, char, *)
INST_GENERATE(mul16, short, *)
INST_GENERATE(mul32, int, *)
INST_GENERATE(mul64, long int, *)

INST_GENERATE(div8, char, /)
INST_GENERATE(div16, short, /)
INST_GENERATE(div32, int, /)
INST_GENERATE(div64, long int, /)
