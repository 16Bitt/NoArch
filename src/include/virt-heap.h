#ifndef __VIRT_HEAP_H
#define __VIRT_HEAP_H

void* virt_malloc(unsigned int s);
void virt_free(void* ptr);

#endif
