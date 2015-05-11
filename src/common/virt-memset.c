#include "virt-common.h"

void virt_memset(void* ptr, char val, unsigned int length){
	unsigned int i;
	for(i = 0; i < length; i++)
		((char*) ptr)[i] = val;
}
