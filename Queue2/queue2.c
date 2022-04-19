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
	Item* tmp = (Item*)malloc(2 * queue->capacity * sizeof(Item));
	if (tmp == NULL)
		terminate("Error in create : queue could not be xpanded.");

	int index = queue->front;

	for (int i = 0; i < queue->size; i++) {
		tmp[i] = queue->contents[index];
		index = (index + 1) % queue->capacity;
	}
	free(queue->contents);
	
	queue->contents = tmp;
	queue->front = 0;
	queue->rear = queue->size - 1;
	queue->size *= 2;
	queue->capacity *= 2;
}

Item Dequeue(Queue queue)
{
	if (Is_empty(queue))
		terminate("Error in dequeue : queue is empty.");

	Item result = queue->contents[queue->front];
	
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return result;
}

Item Peek(Queue queue)
{
	if (Is_empty(queue))
		terminate("Error in peek : queue is empty.");
	return queue->contents[queue->front];
}

void Print_queue(Queue queue)
{
	if (Is_empty(queue))
		//terminate("Error in Print_queue : queue is empty.");
		printf("queue is empty.\n");
	else {
		printf("Front : %d\n", queue->front);
		printf("Rear : %d\n", queue->rear);

		int index = queue->front;

		for (int i = 0; i < queue->size; i++) {
			printf("%d", queue->contents[index]);
			index = (index + 1) % queue->capacity;
			if (i < queue->size - 1)
				printf(" --> ");
		}
		printf("\n\n");
	}
}