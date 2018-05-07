#pragma once
#define DataType int
typedef struct Node {
	DataType data;
	struct Node * next;
}qNode;

//���ڴ�ͷ���ĵ��������
typedef struct Queue {
	qNode * front;
	qNode * tail;
}LQueue;
//��ʼ������
void InitQueue(LQueue *queue);
//������Ԫ��
void PushQueue(LQueue *queue, DataType data);
//���г�Ԫ��
void PopQueue(LQueue * queue);
//��ȡ��ͷԪ��
DataType QueueFront(LQueue* queue);
//��ȡ��βԪ��
DataType QueueTail(LQueue* queue);
//��ȡ���г���
int QueueSize(LQueue* queue);
//�п�
int QueueEmpyt(LQueue* queue);
//���ٶ���
void DestoryQueue(LQueue** queue);