#ifndef __QUEUE2_H__
#define __QUEUE2_H__

#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INIT_CAPACITY 100

typedef struct queue* Queue;
typedef int Item;

struct queue {
	Item* contents;	// �迭
	int front;
	int rear;
	int size;	// ����� �������� ����
	int capacity;	// �迭 contents�� ũ��
};

void terminate(const char*);
int get_size(Queue);	
Queue Create_queue();
void Destroy(Queue);
void Make_empty(Queue);
bool Is_empty(Queue);
bool Is_full(Queue);
void Enqueue(Queue, Item);
void Reallocate(Queue);
Item Dequeue(Queue);
Item Peek(Queue);