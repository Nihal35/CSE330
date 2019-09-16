//Name: Nihal Mandava
#include <stdio.h>
#include "sem.h"
void thread1();
void thread2();

SEM_t* ptr;        //main class to run 

void thread1()       //first thread
{
	P(ptr);
	int counter = 0;
	while (counter >= 0)
	{
		counter++;
		printf("thread1\n");
		sleep(1);
		V(ptr);
	}
}

void thread2() //2nd thread
{
	P(ptr);
	int counter = 0;
	while (counter >= 0)
	{
		counter++;
		printf("thread2\n");
		sleep(1);
		printf("Iteration done\n");
		sleep(1);
		V(ptr);
	}
}

int main()
{
	ptr = malloc(sizeof(SEM_t));
	InitSem(ptr, 1);
	RunQ = NewItem();
	InitQueue(&RunQ);
	start_thread(thread1);
	start_thread(thread2);
	run();
	return 0;
}

