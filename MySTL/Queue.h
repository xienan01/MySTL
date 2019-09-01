#ifndef QUEUE_H
#define QUEUE_H
const int QueueSize = 60;
typedef int DataType;

typedef struct List_Queue 
{
	DataType queue[QueueSize];
	int front, rear;
}SeqQueue;

// ��ʽ����
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

	// FIFO ��ͷ(front)   ��β(rear)
public:
	// ��ʼ������
	void InitQueue(SeqQueue *Q);
	// �п�
	bool QueueEmpty(SeqQueue Q);
	// ����Ԫ�ص���β
	int EnterQueue(SeqQueue Q, DataType e);
	// ɾ��Ԫ��
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

	// FIFO ��ͷ(front)   ��β(rear)
public:
	// ��ʼ������
	void InitLinkQueue(Link_Queue *Q);
	// �п�
	bool LinkQueueEmpty(Link_Queue Q);
	// ����Ԫ�ص���β
	int EnterLinkQueue(Link_Queue Q, DataType e);
	// ɾ��Ԫ��
	int DeleteLinkQueueHead(Link_Queue Q, DataType *e);
	// 
	int GetLinkQueueElem(Link_Queue Q, DataType *e);
	// 
	void ClearLinksQueue(Link_Queue);
};





#endif