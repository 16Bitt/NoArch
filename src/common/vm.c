#include "virt-text.h"
#include "virt-runtime.h"
#include "virt-heap.h"
#include "virt-common.h"

virt_proc_t* init_proc(long int ip, int stack_size, int rstack_size, long int* mem){
	virt_proc_t* proc = (virt_proc_t*) virt_malloc(sizeof(virt_proc_t));
	virt_memset(proc, 0, sizeof(virt_proc_t));
	proc->mem =  mem;
	proc->stack = (long int*) virt_malloc(sizeof(long int) * stack_size);
	proc->rstack = (long int*) virt_malloc(sizeof(long int) * rstack_size);
	proc->ip = ip;

	return proc;
}

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

#define MATH_GENERATE(name, type, op) void virt_ ## name (virt_proc_t* proc){ \
	type n1 = (type) virt_pop(proc); \
	type n2 = (type) virt_pop(proc); \
	virt_push(proc, n2 op n1); \
}

#define PEEK_GENERATE(name, type)
#define POKE_GENERATE(name, type)
#define LIT_GENERATE(name, type);

MATH_GENERATE(add8, char, +)
MATH_GENERATE(add16, short, +)
MATH_GENERATE(add32, int, +)
MATH_GENERATE(add64, long int, +)

MATH_GENERATE(sub8, char, -)
MATH_GENERATE(sub16, short, -)
MATH_GENERATE(sub32, int, -)
MATH_GENERATE(sub64, long int, -)

MATH_GENERATE(mul8, char, *)
MATH_GENERATE(mul16, short, *)
MATH_GENERATE(mul32, int, *)
MATH_GENERATE(mul64, long int, *)

MATH_GENERATE(div8, char, /)
MATH_GENERATE(div16, short, /)
MATH_GENERATE(div32, int, /)
MATH_GENERATE(div64, long int, /)

PEEK_GENERATE(peek8, char)
PEEK_GENERATE(peek16, short)
PEEK_GENERATE(peek32, int)
PEEK_GENERATE(peek64, long int)

POKE_GENERATE(poke8, char)
POKE_GENERATE(poke16, short)
POKE_GENERATE(poke32, int)
POKE_GENERATE(poke64, long int)
