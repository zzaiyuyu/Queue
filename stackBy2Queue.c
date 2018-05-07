#include "stackBy2Queue.h"
#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//��ʼ��ջ
void StackBy2QueueInit(pStackByQ s)
{
	assert(s);
	InitQueue(&s->queue1);
	InitQueue(&s->queue2);
}

//��ջ
void StackBy2QueuePush(pStackByQ s, DataType data)
{
	assert(s);
	//����������һ��Ϊ�գ�һ�������ݣ��������ݵĶ��з�����
	if (QueueEmpyt(&s->queue1) && QueueEmpyt(&s->queue2) || !QueueEmpyt(&s->queue1)) {
		PushQueue(&s->queue1, data);
	}
	else {
		PushQueue(&s->queue2, data);
	}
}

//��ջ
void StackBy2QueuePop(pStackByQ s)
{
	assert(s);
	int size = 0;
	if (!QueueEmpyt(&s->queue1)) {
		size = QueueSize(&s->queue1) - 1;
		while (size--) {
			PushQueue(&s->queue2, QueueFront(&s->queue1));
			PopQueue(&s->queue1);
		}
		PopQueue(&s->queue1);
	}
	else if (!QueueEmpyt(&s->queue2)) {
		size = QueueSize(&s->queue1) - 1;
		while (size--) {
			PushQueue(&s->queue2, QueueFront(&s->queue1));
			PopQueue(&s->queue1);
		}
		PopQueue(&s->queue1);
	}
	else {
		printf("ջ��\n");
	}
}

//�п� 
int StackBy2QueueEmpty(pStackByQ s)
{
	assert(s);
	if (QueueEmpyt(&s->queue1) && QueueEmpyt(&s->queue2)) {
		return 1;
	}
	return 0;
}
//�鿴ջ��Ԫ��
DataType StackBy2QueueTop(pStackByQ s)
{
	assert(s);
	if (StackBy2QueueEmpty(s)) {
		exit(EXIT_FAILURE);
	}
	if (!QueueEmpyt(&s->queue1)) {
		return QueueTail(&s->queue1);
	}
	else {
		return QueueTail(&s->queue2);
	}
}

//�鿴ջ���Ԫ�ظ���
int StackBy2QueueSize(pStackByQ s)
{
	assert(s);
	if (StackBy2QueueEmpty(s)) {
		return 0;
	}
	else {
		int size1 = QueueSize(&s->queue1);
		int size2 = QueueSize(&s->queue2);
		return  size1 ? size1 : size2;
	}
}

//����
void TestStackBy2Queue()
{
	StackByQ stack;
	StackBy2QueueInit(&stack);
	StackBy2QueuePush(&stack, 1);

	StackBy2QueuePush(&stack, 2);
	StackBy2QueuePush(&stack, 3);
	int emp = StackBy2QueueEmpty(&stack);
	int size = StackBy2QueueSize(&stack);
	int top = StackBy2QueueTop(&stack);
	StackBy2QueuePop(&stack);
	StackBy2QueuePush(&stack, 4);
	int t = StackBy2QueueTop(&stack);


}