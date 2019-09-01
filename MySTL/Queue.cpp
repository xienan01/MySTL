#include "Queue.h"
#include "iostream"

ListQueue::ListQueue()
{

}

ListQueue::~ListQueue()
{

}

void ListQueue::InitQueue(SeqQueue *Q)
{
	Q->front = Q->rear = 0;
}

bool ListQueue::QueueEmpty(SeqQueue Q)
{
	if(Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ListQueue::EnterQueue(SeqQueue Q, DataType e)
{
	if(Q.front == (Q.rear+1)%QueueSize)
	{
		std::cout << "The Queue is Full";
		exit(0);
	}
	else
	{
		Q.queue[Q.rear] = e;
		Q.rear = (Q.rear+1)&QueueSize;
	}
}

int ListQueue::DeleteQueueHead(SeqQueue Q, DataType *e)
{
	if(Q.rear = Q.front)
	{
		std::cout << "Queue is Empty";
		exit(0);
	}
	else
	{
		*e =  Q.queue[Q.front];
		Q.front = (Q.front+1) % QueueSize;
	}
}
 
int ListQueue::GetQueueElem(SeqQueue Q, DataType *e)
{
	if(Q.rear = Q.front)
	{
		std::cout << "Queue is Empty";
		exit(0);
	}
	else
	{
	*e =  Q.queue[Q.front];
	}
	return 0;
}

void ListQueue::ClearQueue(SeqQueue Q)
{
	Q.front = Q.rear = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
LinkQueue::LinkQueue()
{

}

LinkQueue::~LinkQueue()
{

}

void LinkQueue::InitLinkQueue(Link_Queue *Q)
{
	Q->front = Q->rear = (Link_Queue_Node*)malloc(sizeof(Link_Queue_Node));
	if(Q->front == NULL)
	{
		std::cout << "Init Failed!";
		exit(0);
	}
	else
	{
		Q->front->Next = NULL;
	}
}

bool LinkQueue::LinkQueueEmpty(Link_Queue Q)
{
	if(Q.rear->Next = NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkQueue::EnterLinkQueue(Link_Queue Q, DataType e)
{
	Link_Queue_Node *p = (Link_Queue_Node*)malloc(sizeof(Link_Queue_Node));
	if(p == NULL)
	{
		std::cout << "malloc Error !";
		exit(0);
	}
	else
	{
		p->data = e;
		p->Next = NULL;
		Q.rear->Next = p;
		Q.rear = p;
	}
	return 0;
}

int LinkQueue::DeleteLinkQueueHead(Link_Queue Q, DataType *e)
{
	Link_Queue_Node *p;
	if(Q.front == Q.rear)
	{
		std::cout << "Queue is Empty";
		exit(0);
	}
	else
	{
		p=Q.front->Next;
		*e = p->data;
		Q.front->Next = p->Next;
		if(Q.rear == p)
		{
			Q.rear = Q.front;
		}
		free(p);
	}
	return 0;
}

int LinkQueue::GetLinkQueueElem(Link_Queue Q, DataType *e)
{
	Link_Queue_Node *p;
	if(Q.front == Q.rear)
	{
		std::cout << "Queue is Empty";
		exit(0);
	}
	else
	{
		p = Q.front->Next;
		*e = p->data;
	}
	return 0;
}

void LinkQueue::ClearLinksQueue(Link_Queue Q)
{
	while(Q.front != NULL)
	{
		Q.rear = Q.front->Next;
		free(Q.front);
		Q.front = Q.front;
	}
}
