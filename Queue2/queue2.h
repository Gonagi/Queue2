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
	Item* contents;	// 배열
	int front;
	int rear;
	int size;	// 저장된 데이터의 개수
	int capacity;	// 배열 contents의 크기
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