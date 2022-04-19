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

void Destroy(Queue queue)
{
	free(queue->contents);
	free(queue);
}

void Make_empty(Queue queue)
{
	queue->front = 0;
	queue->rear = -1;
	queue->size = 0;
}

bool Is_empty(Queue queue)
{
	return queue->size == 0;
}

bool Is_full(Queue queue)
{
	return queue->size == queue->capacity;
}

void Enqueue(Queue queue, Item data)
{
	if (Is_full(queue))
		Reallocate(queue);

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->contents[queue->rear] = data;
	queue->size++;
}

void Reallocate(Queue queue)
{
	Item a[INIT_CAPACITY];

	for (int i = 0; i < queue->size; i++) 
		a[i] = queue->contents[i];

	queue->contents = (Item*)malloc(2 * INIT_CAPACITY * sizeof(Item));
	
	for (int i = 0; i < queue->size; i++)
		queue->contents[i] = a[i];

	queue->capacity *= 2;
}

Item Dequeue(Queue queue)
{
	if (Is_empty(queue))
		terminate("Error in dequeue : queue is empty.");

	Item result = queue->contents[queue->front];
	
	queue->front = (queue->front + 1) % queue->capacity;
	//queue->front++;
	//if (queue->front >= queue->capacity)
	//	queue->front = 0;
	queue->size--;
	return result;
}

Item Peek(Queue queue)
{
	if (Is_empty(queue))
		terminate("Error in peek : queue is empty.");
	return queue->contents[queue->front];
}