#include "queue.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
qNode * BuyNode(DataType data)
{
	qNode * new = (qNode*)malloc(sizeof(qNode));
	if (NULL == new) {
		printf("����ʧ��");
		return NULL;
	}
	new->data = data;
	new->next = NULL;
	return new;
}
void InitQueue(LQueue *queue)
{
	assert(queue);
	//����ͷ���
	qNode * head= BuyNode(0);
	queue->front = head;
	queue->tail = head;
}
void PushQueue(LQueue *queue, DataType data)
{
	qNode *new = BuyNode(data);
	queue->tail->next = new;
	queue->tail = new;
}
void PopQueue(LQueue * queue)
{
	qNode *pDel = queue->front->next;
	//���ǿն���
	if (pDel) {
		//��ͷ���ֻ��һ�����
		if (NULL == pDel->next) {
			queue->tail = queue->front;
		}
		queue->front->next = pDel->next;
		free(pDel);
	}
}

DataType QueueFront(LQueue* queue)
{
	//��Ԫ��
	if (queue->front->next) {
		return queue->front->next->data;
	}
	exit(EXIT_FAILURE);
}
//��ȡ��βԪ��
DataType QueueTail(LQueue* queue)
{
	if (queue->tail == queue->front) {
		exit(EXIT_FAILURE);
	}
	return queue->tail->data;
}
int QueueSize(LQueue* queue)
{
	int count = 0;
	qNode * pcur = queue->front->next;
	while (pcur) {
		count++;
		pcur = pcur->next;
	}
	return count;
}
int QueueEmpyt(LQueue* queue)
{
	if (queue->front == queue->tail) {
		return 1;
	}
	return 0;
}
void DestoryQueue(LQueue** queue)
{
	if (*queue != NULL) {
		while ((*queue)->front) {
			PopQueue(*queue);
		}
		free(*queue);
		*queue = NULL;
	}

}