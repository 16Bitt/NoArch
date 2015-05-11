#include "virt-heap.h"
#include "stdlib.h"

void virt_free(void* ptr){
	free(ptr);
}
