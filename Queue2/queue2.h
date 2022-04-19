#ifndef __QUEUE2_H__
#define __QUEUE2_H__

#endif
#include <stdio.h>
#include <stdlib.h>

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