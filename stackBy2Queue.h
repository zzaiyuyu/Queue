#include "queue.h"

typedef struct TWOQ {
	LQueue queue1;
	LQueue queue2;
}StackByQ, *pStackByQ;

//��ʼ��ջ
void StackBy2QueueInit(pStackByQ s);

//��ջ
void StackBy2QueuePush(pStackByQ s, DataType data);

//��ջ
void StackBy2QueuePop(pStackByQ s);

//�鿴ջ��Ԫ��
DataType StackBy2QueueTop(pStackByQ s);

//�鿴ջ���Ԫ�ظ���
int StackBy2QueueSize(pStackByQ s);

//�п� 
int StackBy2QueueEmpty(pStackByQ s);

//����
void TestStackBy2Queue();