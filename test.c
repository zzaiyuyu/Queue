#include "queue.h"
#include "stackBy2Queue.h"
int main()
{
	TestStackBy2Queue();
	LQueue queue;
	InitQueue(&queue);
	PushQueue(&queue, 8);
	PushQueue(&queue, 7);
	PushQueue(&queue, 9);
	DataType ret = QueueFront(&queue);
	int size = QueueSize(&queue);
	int emp = QueueEmpyt(&queue);
	PopQueue(&queue);
	PopQueue(&queue);
	PopQueue(&queue);

	DestoryQueue(&queue);

}