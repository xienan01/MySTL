#ifndef Stack_H
#define Stack_H

const int Stack_Size = 100;
typedef int DataType;

typedef struct
{
	DataType stack[Stack_Size];
	int top;
}Seq_Stack;

typedef struct
{
	DataType stack[Stack_Size];
	int top[2];
}Shared_Stack;


typedef struct Node
{
	DataType  data;
	Node *Next;
}Link_Stack_Node, *Link_Stack;


class Stack 
{
public:
	Stack();
	virtual ~Stack();

	//stack ���޶������ڱ��β�����в����ɾ�����������Ա�
public:
	//��ʼ��
	void InitStack(Seq_Stack *s);
	//�ж�Ϊ��
	bool StackEmpty(Seq_Stack *s);
	//ȡջ��Ԫ��
	int GetTopElem(Seq_Stack s, DataType *e);
	// ��ջ
	int PushStack(Seq_Stack *s, DataType e);
	// ��ջ
	int PopStack(Seq_Stack *s, DataType *e);
	//��ջ��
	int StackLength(Seq_Stack s);
	// ���ջ
	void ClearStack(Seq_Stack s);
};


class SharedStack 
{
public:
	SharedStack();
	virtual ~SharedStack();

	//Shared_Stack �Ǵ����˽��в�����stack
public:
	void InitShared_Stack(Shared_Stack *s);

	bool Shared_StackEmpty(Shared_Stack *s, int flag);

	int GetShared_StackTopElem(Shared_Stack s, DataType *e, int flag);

	int PushShared_Stack(Shared_Stack *s, DataType e, int flag);
	
	int PopShard_Stack(Shared_Stack *s, DataType *e, int flag);

	int Shared_StackLength(Shared_Stack s, int flag);
	
	void ClearShared_Stack(Shared_Stack s, int flag);
};


class LinkStack 
{
public:
	LinkStack();
	virtual ~LinkStack();

	//Link_Stack ��ջ������ʽջ
public:
	void InitLink_Stack(Link_Stack *s);

	bool Link_StackEmpty(Link_Stack s);

	int GetLink_StackTopElem(Link_Stack s, DataType *e);

	int PushLink_Stack(Link_Stack s, DataType e);
	
	int PopLink_Stack(Link_Stack s, DataType *e);

	int Link_StackLength(Link_Stack s);
	
	void ClearLink_Stack(Link_Stack s);
};

#endif