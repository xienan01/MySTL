#ifndef LIST_H
#define LIST_H

#define LISTSIZE 100
typedef int DataType;

 // ˳���ڵ���Ϣ
typedef struct
{
	DataType  List[LISTSIZE];
	int length;
}SeqList;

class List
{
public:
	List();
	virtual ~List();

public:
	// ����һ��List
	void InitList(SeqList *L);
	//�ж϶����Ƿ�Ϊ��
	bool  ListEmpty(SeqList L);
	// ����Ų���
	int GetElement(SeqList L, int iNum, DataType *e);
	// �������ݲ���
	int LocateElement(SeqList L, DataType e);
	//��i��λ���ϲ���Ԫ��e
	bool InsertList(SeqList* L,int iNum, DataType e);
	//ɾ����i��Ԫ��
	bool DeleteList(SeqList* L,int iNum);
    // �����Ա�ĳ���
	int GetListLength(SeqList L);
	//������Ա�
	void ClearList(SeqList L);

private:
	SeqList* pList;   // һ��ָֻ��ṹ���ָ��
};

 // ������ڵ���Ϣ
typedef struct LinkList_Node
{
	DataType  LinkList_Data;
	LinkList_Node *next;
}SeqLinkNode, *pLinkList;

class LinkList
{
public:
	LinkList();
	virtual ~LinkList();

public:
	// ����һ��List
	void InitLinkList(pLinkList *L);
	//�ж϶����Ƿ�Ϊ��
	bool  LinkListEmpty(pLinkList L);
	// ����Ų���
	int GetElement(pLinkList L, int iNum, LinkList_Node *e);
	// �������ݲ���
	 LinkList_Node* LocateElement(pLinkList L, DataType e);
	//��i��λ���ϲ���Ԫ��e
	bool InsertLinkList(pLinkList L,int iNum, DataType e);
	//ɾ����i��Ԫ��
	bool DeleteLinkList(pLinkList L,int iNum, DataType *e);
    // �����Ա�ĳ���
	int GetLinkListLength(pLinkList L);
	//������Ա�
	void ClearLinkList(pLinkList L);
};


//ѭ��������
class CirLinkList : public LinkList
{
public :
	CirLinkList();

	virtual ~CirLinkList();

public:

	pLinkList Link(pLinkList head1, pLinkList head2);

	bool  CirLinkListEmpty(pLinkList L);
};


//˫������
typedef struct DCirLinkList
{
	DataType Data;
	struct DCirLinkList *Prior;
	struct DCirLinkList *Next;
} DLinkList_Node, *DLinkList;


class DoubleCirLinkList
{
public:
	DoubleCirLinkList();
	virtual ~DoubleCirLinkList();

public:
	// ����һ��˫����
	void InitDoubleCirLinkList(DLinkList *head);
	//�ж�˫�����Ƿ�Ϊ��
	bool  DLinkListEmpty(DLinkList L);
	// ����Ų��ҵ�i��Ԫ��
	int GetDLinkListElement(DLinkList L, int iNum, LinkList_Node *e);
	// �������ݲ���
	 DLinkList* LocateDLinkListElement(DLinkList L, DataType e);
	//��i��λ���ϲ���Ԫ��e
	bool InsertDLinkList(DLinkList L,int iNum, DataType e);
	//ɾ����i��Ԫ��
	bool DeleteDLinkList(DLinkList L,int iNum, DataType *e);
};

#endif