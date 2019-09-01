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

	//stack 是限定仅仅在表的尾部进行插入和删除操作的线性表
public:
	//初始化
	void InitStack(Seq_Stack *s);
	//判断为空
	bool StackEmpty(Seq_Stack *s);
	//取栈顶元素
	int GetTopElem(Seq_Stack s, DataType *e);
	// 入栈
	int PushStack(Seq_Stack *s, DataType e);
	// 出栈
	int PopStack(Seq_Stack *s, DataType *e);
	//求栈长
	int StackLength(Seq_Stack s);
	// 清空栈
	void ClearStack(Seq_Stack s);
};


class SharedStack 
{
public:
	SharedStack();
	virtual ~SharedStack();

	//Shared_Stack 是从两端进行操作的stack
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

	//Link_Stack 链栈或者链式栈
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