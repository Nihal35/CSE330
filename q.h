#include <stdlib.h>
#include "tcb.h"
#include <unistd.h>
struct TCB_t *NewItem();
void InitQueue(struct TCB_t** newHead);
void AddQueue(struct TCB_t** head, struct TCB_t* item);
struct TCB_t* DelQueue(struct TCB_t** head);
void RotateQ(struct TCB_t** head);


int count;
struct TCB_t* first, * last;


TCB_t *NewItem(){ 
	
	TCB_t* q = (TCB_t*)malloc(sizeof(TCB_t));
	return q;

}



void InitQueue(struct TCB_t** newHead) {
	first = *newHead;
	count = 0;
}
void AddQueue(struct TCB_t** head, struct TCB_t* item)
{
	if (count != 0) {
		item->prev = last;
		last->next = item;
		
		last = item;
		
	}

	else {
		*head = item;

		(*head)->prev = *head;
		last = (*head)->prev;

		(*head)->next = *head;
		first = *head;
	}

	first->prev = last;
	last->next = first;
	count++;
}

struct TCB_t* DelQueue(struct TCB_t** head)
{
	struct TCB_t* beg;
	beg = *head;
	*head = (*head)->next;
	first = *head;
	first->prev = last;
	last->next = first;

	count--;
	return beg;
}

void RotateQ(struct TCB_t** head)
{
	AddQueue(head, DelQueue(head));
}




