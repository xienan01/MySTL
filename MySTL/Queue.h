#ifndef QUEUE_H
#define QUEUE_H
const int QueueSize = 60;
typedef int DataType;

typedef struct List_Queue 
{
	DataType queue[QueueSize];
	int front, rear;
}SeqQueue;

// 链式队列
typedef struct Link_Queue_Node 
{
	DataType data;
	Link_Queue_Node* Next;
}Link_Queue_Node, *Link_Queue_t;

typedef struct
{
	Link_Queue_t front;
	Link_Queue_t rear;
}Link_Queue;

class ListQueue
{
public:
	ListQueue();
	virtual~ListQueue();

	// FIFO 队头(front)   队尾(rear)
public:
	// 初始化队列
	void InitQueue(SeqQueue *Q);
	// 判空
	bool QueueEmpty(SeqQueue Q);
	// 插入元素到队尾
	int EnterQueue(SeqQueue Q, DataType e);
	// 删除元素
	int DeleteQueueHead(SeqQueue Q, DataType *e);
	// 
	int GetQueueElem(SeqQueue Q, DataType *e);
	// 
	void ClearQueue(SeqQueue Q);
};


class LinkQueue
{
public:
	LinkQueue();
	virtual~LinkQueue();

	// FIFO 队头(front)   队尾(rear)
public:
	// 初始化队列
	void InitLinkQueue(Link_Queue *Q);
	// 判空
	bool LinkQueueEmpty(Link_Queue Q);
	// 插入元素到队尾
	int EnterLinkQueue(Link_Queue Q, DataType e);
	// 删除元素
	int DeleteLinkQueueHead(Link_Queue Q, DataType *e);
	// 
	int GetLinkQueueElem(Link_Queue Q, DataType *e);
	// 
	void ClearLinksQueue(Link_Queue);
};





#endif