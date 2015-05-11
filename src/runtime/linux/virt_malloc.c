#include "virt-heap.h"
#include "stdlib.h"

void* virt_malloc(unsigned int s){
	return malloc(s);
}
