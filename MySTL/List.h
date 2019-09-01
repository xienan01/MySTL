#ifndef LIST_H
#define LIST_H

#define LISTSIZE 100
typedef int DataType;

 // 顺序表节点信息
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
	// 创建一个List
	void InitList(SeqList *L);
	//判断队列是否为空
	bool  ListEmpty(SeqList L);
	// 按序号查找
	int GetElement(SeqList L, int iNum, DataType *e);
	// 按照内容查找
	int LocateElement(SeqList L, DataType e);
	//在i的位置上插入元素e
	bool InsertList(SeqList* L,int iNum, DataType e);
	//删除第i个元素
	bool DeleteList(SeqList* L,int iNum);
    // 求线性表的长度
	int GetListLength(SeqList L);
	//清空线性表
	void ClearList(SeqList L);

private:
	SeqList* pList;   // 一个只指向结构体的指针
};

 // 单链表节点信息
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
	// 创建一个List
	void InitLinkList(pLinkList *L);
	//判断队列是否为空
	bool  LinkListEmpty(pLinkList L);
	// 按序号查找
	int GetElement(pLinkList L, int iNum, LinkList_Node *e);
	// 按照内容查找
	 LinkList_Node* LocateElement(pLinkList L, DataType e);
	//在i的位置上插入元素e
	bool InsertLinkList(pLinkList L,int iNum, DataType e);
	//删除第i个元素
	bool DeleteLinkList(pLinkList L,int iNum, DataType *e);
    // 求线性表的长度
	int GetLinkListLength(pLinkList L);
	//清空线性表
	void ClearLinkList(pLinkList L);
};


//循环单链表
class CirLinkList : public LinkList
{
public :
	CirLinkList();

	virtual ~CirLinkList();

public:

	pLinkList Link(pLinkList head1, pLinkList head2);

	bool  CirLinkListEmpty(pLinkList L);
};


//双向链表
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
	// 创建一个双链表
	void InitDoubleCirLinkList(DLinkList *head);
	//判断双链表是否为空
	bool  DLinkListEmpty(DLinkList L);
	// 按序号查找第i个元素
	int GetDLinkListElement(DLinkList L, int iNum, LinkList_Node *e);
	// 按照内容查找
	 DLinkList* LocateDLinkListElement(DLinkList L, DataType e);
	//在i的位置上插入元素e
	bool InsertDLinkList(DLinkList L,int iNum, DataType e);
	//删除第i个元素
	bool DeleteDLinkList(DLinkList L,int iNum, DataType *e);
};

#endif