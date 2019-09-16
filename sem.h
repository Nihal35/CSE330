#include "threads.h"

typedef struct SEM_t {
	int value;
	struct TCB_t* queue;
} SEM_t;

void InitSem(SEM_t* semaphore, int x);
void P(SEM_t* sempaphore);
void V(SEM_t* semaphore);

void InitSem(SEM_t* semaphore, int x) {
	semaphore->value = x;
}

void P(SEM_t* semaphore) {
	semaphore->value = semaphore->value - 1;       //block 
	if (semaphore->value < 0) {
		TCB_t* a = DelQueue(&RunQ);
		AddQueue(&(semaphore->queue), a);
	}
}

void V(SEM_t* semaphore) {
	semaphore->value = semaphore->value + 1;          //unblock
	if (semaphore->value < 0 || semaphore->value == 0) {
		TCB_t* b = DelQueue(&semaphore->queue);
		AddQueue(&RunQ, b);
	}
	yield();
}