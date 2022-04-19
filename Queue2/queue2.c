#include "queue2.h"

void terminate(const char* message)
{
	printf("%s\n", message);
	exit(1);
}

int get_size(Queue q)
{
	return q->size;
}

Queue Create_queue()
{
	Queue new_queue = (Queue)malloc(sizeof(struct queue));
	if (new_queue == NULL)
		terminate("Error in create : queue could not be created.");
	
	new_queue->contents = (Item*)malloc(INIT_CAPACITY * sizeof(Item));
	if (new_queue->contents == NULL) {
		free(new_queue);
		terminate("Error in create : queue cold not be crerated.");
	}

	new_queue->front = 0;
	new_queue->rear = -1;
	new_queue->size = 0;
	new_queue->capacity = INIT_CAPACITY;
	return new_queue;
}