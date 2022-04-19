#include "queue2.h"

int main()
{
	Queue q1 = Create_queue();
	Queue q2 = Create_queue();
	Queue q3 = Create_queue();

	Enqueue(q1, 1);
	Enqueue(q2, 10);
	Enqueue(q3, 100);
	Enqueue(q3, 200);

	Print_queue(q1);
	Print_queue(q2);
	Print_queue(q3);

	printf("q1 Peek : %d\n", Peek(q1));
	printf("q1 Dequeue : %d\n", Dequeue(q1));
	printf("q2 Dequeue : %d\n", Dequeue(q2));

	printf("\n\n");

	q1 = Create_queue();
	q2 = Create_queue();

	Enqueue(q2, 20);
	Enqueue(q2, 30);
	Enqueue(q2, 40);
	Enqueue(q3, 300);

	Print_queue(q1);
	Print_queue(q2);
	Print_queue(q3);
	_CrtDumpMemoryLeaks();
	return 0;
}