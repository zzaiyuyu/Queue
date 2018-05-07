#pragma once
#define DataType int
typedef struct Node {
	DataType data;
	struct Node * next;
}qNode;

//基于带头结点的单链表队列
typedef struct Queue {
	qNode * front;
	qNode * tail;
}LQueue;
//初始化队列
void InitQueue(LQueue *queue);
//队列入元素
void PushQueue(LQueue *queue, DataType data);
//队列出元素
void PopQueue(LQueue * queue);
//获取队头元素
DataType QueueFront(LQueue* queue);
//获取队尾元素
DataType QueueTail(LQueue* queue);
//获取队列长度
int QueueSize(LQueue* queue);
//判空
int QueueEmpyt(LQueue* queue);
//销毁队列
void DestoryQueue(LQueue** queue);