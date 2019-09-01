#include "List.h"
#include "iostream"

List::List()
{

}

List::~List()
{

}

void List::InitList(SeqList *L)
{
	L->length = 0;
}

bool List::ListEmpty(SeqList L)
{
	if(L.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int List::GetElement(SeqList L, int iNum, DataType *e)
{
	if (iNum > L.length || iNum <1)
	{
		return -1;
	}
	else
	{
		*e = L.List[iNum -1];
	}
	return 0;
}


// �������ݲ���
int List::LocateElement(SeqList L, DataType e)
{
	for(int i=0; i< L.length -1; i++)
	{
		if(L.List[i] == e)
		{
			return i + 1;
		}
		else
		{
			return 0;
		}
	}
}

bool List::InsertList(SeqList* L,int iNum, DataType e)
{
	if(iNum < 1 || iNum > L->length)
	{
		std::cout << "The iNum is illegal" << std::endl;
		return false;
	}
	else if(L->length = LISTSIZE)
	{
		std::cout << "The List is full" << std::endl;
		return false;
	}
	else
	{
		for(int i =  L->length - 1; i > iNum - 1; i--)
		{
			L->List[i] = L->List[i-1];
		}
		L->List[iNum-1] = e;
		L->length ++;
	}
	return 0;
}

bool List::DeleteList(SeqList* L,int iNum)
{
	if(iNum < 1 || iNum > L->length)
	{
		std::cout << "The iNum is illegal" << std::endl;
		return false;
	}
	else if(L->length = 0)
	{
		std::cout << "The List is Empty" << std::endl;
		return false;
	}
	else
	{
		if(iNum < L->length)
		{
			for(int i =iNum-1; i < L->length -1; i++)
			{
				L->List[i] = L->List[i+1];
			}
		}
		L->length --;
	}
	return 0;
}

int List::GetListLength(SeqList L)
{

	return L.length;
}

void List::ClearList(SeqList L)
{
	L.length = 0;
}






/*****************************************************  ������ ***********************************************************/

LinkList::LinkList()
{


}


LinkList::~LinkList()
{


}

// ����һ��LinkList
void LinkList::InitLinkList(pLinkList *head)
{
	*head = (pLinkList)malloc(sizeof(SeqLinkNode));
	if(*head == NULL)
	{
		return;
	}
	(*head)->next = NULL;
}

//�ж϶����Ƿ�Ϊ��
bool  LinkList::LinkListEmpty(pLinkList head)
{
	if (head ->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ����Ų���
int LinkList::GetElement(pLinkList L, int iNum, LinkList_Node *e)
{
	if(LinkListEmpty(L))
	{
		std::cout << "The LinkList is Empty! \n";
	return -1;
	}
	else if(iNum < 1)
	{
	std::cout << "The iNum is ileagal! \n";
	return -2;
	}
	else
	{
		for(int j = 0; j < iNum; j++)
		{
			L = L->next;
		}
		e = L->next;
	}
	return 0;
}
// �������ݲ���
LinkList_Node* LinkList::LocateElement(pLinkList L, DataType e)
{
	if(LinkListEmpty(L))
	{
		std::cout << "The LinkList is Empty! \n";
		return NULL;
	}
	else
	{
		LinkList_Node* head;
		head = L->next;
		while(head)
		{
			if(head->LinkList_Data != e)
			{
				head = head->next;
				return head;
			}
		}
	}
}
//��i��λ���ϲ���Ԫ��e
bool LinkList::InsertLinkList(pLinkList L,int iNum, DataType e)
{
	LinkList_Node *head, *p;
	head = L;
	int j =0;
	while(head->next != NULL && j<iNum -1)
	{
		head = head->next;
		j++;
	}
	if( j != iNum-1 )
	{
		std::cout << "Insert Location error!";
		return false;
	}

	p= (LinkList_Node*)malloc(sizeof(LinkList_Node));
	if(p != NULL)
	{
		p->LinkList_Data = e;
		p->next = head->next;
		head->next = p;
	}

	return true;
}

//ɾ����i��Ԫ��
bool LinkList::DeleteLinkList(pLinkList L,int iNum, DataType *e)
{
	LinkList_Node *pre, *p;
	int j =0;
	pre = L;
	while(pre->next != NULL && pre->next->next != NULL && j< iNum-1)
	{
		pre = pre->next;
		j++;
	}
	if(j != iNum -1)
	{
		std::cout << "location is ileagle"<< std::endl;
		return -1;
	}

	p=pre->next;
	*e = p->LinkList_Data;
	pre->next = p->next;
	free(p);
	return 0;
}
// �����Ա�ĳ���
int LinkList::GetLinkListLength(pLinkList L)
{
	LinkList_Node *pre;
	pre = L;
	int iLength = 0;
	while(pre->next != NULL)
	{
		pre->next = pre ->next;
		iLength ++;
	}
	return iLength;
}
//������Ա�
void LinkList::ClearLinkList(pLinkList L)
{
	LinkList_Node *pre,*q;
	pre = L;
	while(pre!=NULL)
	{
		q = pre;
		pre = pre->next;
		free(q);
	}
}

/*****************************************************  ����ѭ������ ***********************************************************/
CirLinkList::CirLinkList()
{

}

CirLinkList::~CirLinkList()
{

}

pLinkList CirLinkList::Link(pLinkList head1, pLinkList head2)
{
	LinkList_Node *q,*p;
	p = head1;
	//�ҵ�β�ڵ�
	while(p->next != head1)
	{
		p =p->next;
	}
	p->next = head2->next;  //��һ����β�ڵ��ǵڶ�����ͷ�ڵ�

	q = head2;
	while(q->next != head1) //�ڶ�����β�ڵ��ǵ�һ����ͷ�ڵ�
	{
		q = q->next;
	}
	q->next = head1;
	return head1;
}

bool  CirLinkList::CirLinkListEmpty(pLinkList L)
{
	LinkList_Node *p;
	p =L;
	if(p->next != p)
	{
		return false;
	}
	return true;
}

/*****************************************************  ˫��ѭ������ ***********************************************************/
DoubleCirLinkList::DoubleCirLinkList()
{

}

DoubleCirLinkList::~DoubleCirLinkList()
{

}

// ����һ��LinkList
void DoubleCirLinkList::InitDoubleCirLinkList(DLinkList *head)
{
	*head = (DLinkList)malloc(sizeof(DLinkList));
	if(*head == NULL)
	{
		return;
	}
	(*head)->Next = NULL;
	(*head)->Prior = NULL;
}

bool  DoubleCirLinkList::DLinkListEmpty(DLinkList L)
{
	DLinkList_Node *head;
	head = L;
	if(head->Prior == head || head->Next==head)
	{
		return true;
	}

}

int DoubleCirLinkList::GetDLinkListElement(DLinkList L, int iNum, LinkList_Node *e)
{

}

DLinkList* DoubleCirLinkList::LocateDLinkListElement(DLinkList L, DataType e)
{

}


bool DoubleCirLinkList::InsertDLinkList(DLinkList L,int iNum, DataType e)
{
	DLinkList_Node *p,*q;
	int j;
	p=L;
	while(p->Next!=L&&j<iNum)
	{
		p=p->Next;
		j++;
	}

	q = (DLinkList_Node*) malloc(sizeof(DLinkList_Node));
	if(q!=NULL)
	{
		return -1;
	}
	// �ֳ��Ĳ���
	q->Data = e;
	q->Prior = p->Prior;
	p->Prior->Next = q;
	q->Next = p;
	p->Prior = q;
}


bool DoubleCirLinkList::DeleteDLinkList(DLinkList L,int iNum, DataType *e)
{
	DLinkList_Node *p;
	int j=0;
	p=L;
	while(p->Next!=L&&j<iNum)
	{
		p=p->Next;
		j++;
	}
	if(j!=iNum)
	{
		std::cout << "The Location is Error!";
		exit(0);
	}

	p->Prior->Next = p->Next;
	p->Next->Prior = p->Prior;
	free(p);
	return true;
}