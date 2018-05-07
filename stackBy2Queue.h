#include "queue.h"

typedef struct TWOQ {
	LQueue queue1;
	LQueue queue2;
}StackByQ, *pStackByQ;

//初始化栈
void StackBy2QueueInit(pStackByQ s);

//入栈
void StackBy2QueuePush(pStackByQ s, DataType data);

//出栈
void StackBy2QueuePop(pStackByQ s);

//查看栈定元素
DataType StackBy2QueueTop(pStackByQ s);

//查看栈里的元素个数
int StackBy2QueueSize(pStackByQ s);

//判空 
int StackBy2QueueEmpty(pStackByQ s);

//测试
void TestStackBy2Queue();