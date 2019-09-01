#include "Stack.h"
#include "iostream"


Stack::Stack()
{

}


Stack::~Stack()
{

}

void Stack::InitStack(Seq_Stack* s)
{
	s->top ==0;
}

bool Stack::StackEmpty(Seq_Stack *s)
{
	if(s->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Stack::GetTopElem(Seq_Stack s, DataType *e)
{
	if(s.top == 0)
	{
		std::cout << "The Stack is Empty!";
		exit(0);
	}
	else
	{
		*e = s.stack[s.top-1];
	}
	return 0;
}

int Stack::PushStack(Seq_Stack *s, DataType e)
{
	if(s->top == Stack_Size-1)
	{
		std::cout << "The Stack is Full";
		exit(0);
	}
	else
	{
		s->stack[s->top] = e;
		s->top++;
	}
	return 0;
}

// 出栈
int Stack::PopStack(Seq_Stack *s, DataType *e)
{
	if(s->top == 0)
	{
		std::cout << "The Stack is Empty";
		exit(0);
	}
	else
	{
		s->top --;
		*e = s->stack[s->top];
	}
	return 0;
}

int Stack::StackLength(Seq_Stack s)
{
	return s.top;
}

void Stack::ClearStack(Seq_Stack s)
{
	s.top == 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
SharedStack::SharedStack()
{

}


SharedStack::~SharedStack()
{

}

void SharedStack::InitShared_Stack(Shared_Stack *s)
{
	s->top[0] = 0;
	s->top[1] = Stack_Size -1;
}

bool SharedStack::Shared_StackEmpty(Shared_Stack *s, int flag)
{
	switch(flag)
	{
	case 0:
		if(s->top[0] = 0)
		{
			std::cout << "stack[0] is empty";
		}
		break;
	case 1:
		if(s->top[1] = Stack_Size -1)
		{
			std::cout << "stack[1] is empty";
		}
		break;
	default:
		break;
	}
	return true;
}

int SharedStack::GetShared_StackTopElem(Shared_Stack s, DataType *e, int flag)
{
	switch(flag)
	{
	case 0:
		if(s.top[0] = 0)
		{
			std::cout << "stack[0] is empty";
			return -1;
		}
		else
		{
			*e = s.stack[s.top[0]];
		}
		break;
	case 1:
		if(s.top[1] = Stack_Size-1)
		{
			std::cout << "stack[1] is empty";
			return -1;
		}
		else
		{
			*e = s.stack[s.top[1]];
		}
		break;
	default:
		break;
	}
	return 0;
}

int SharedStack::PushShared_Stack(Shared_Stack *s, DataType e, int flag)
{
	if(s->top[0] = s->top[1])
	{
		std::cout << "stack is empty";
		return -1;
	}
	switch(flag)
	{
	case 0:
		{
			s->stack[s->top[0]] = e;
			s->top[0]++;
		}
		break;
	case 1:
		{
			s->stack[s->top[1]] = e;
			s->top[1]--;
		}
		break;
	default:
		break;
	}
	return  0;
}

int SharedStack::PopShard_Stack(Shared_Stack *s, DataType *e, int flag)
{
	switch(flag)
	{
	case 0:
		if(s->top[0] = 0)
		{
			std::cout << "stack is empty";
			return -1;
		}
		else
		{
			s->top[0]--;
			*e = s->stack[s->top[0]];

		}
		break;
	case 1:
		if(s->top[1] = Stack_Size-1)
		{
			std::cout << "stack is empty";
			return -1;
		}
		else
		{
			s->top[1]++;
			*e = s->stack[s->top[1]];
		}
		break;
	default:
		break;
	}
	return  0;
}

int SharedStack::Shared_StackLength(Shared_Stack s, int flag)
{
	switch(flag)
	{
	case 0:
		return s.top[0];
		break;
	case 1:
		return s.top[1];
		break;
	default: 
		break;
	}
	return 0;
}

void SharedStack::ClearShared_Stack(Shared_Stack s, int flag)
{
	s.top[0] = 0;
	s.top[1] = Stack_Size -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LinkStack::InitLink_Stack(Link_Stack *s)
{
	//需要先分配一个一定大小的节点空间
	*s = (Link_Stack)malloc(sizeof(Link_Stack_Node));
	if(s == NULL)
	{
		std::cout << "Error";
		exit(0);
	}
	else
	{
		(*s)->Next = NULL;
	}
}

bool LinkStack::Link_StackEmpty(Link_Stack s)
{
	if(s->Next == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int LinkStack::GetLink_StackTopElem(Link_Stack s, DataType *e)
{
	Link_Stack_Node *p;
	p = s->Next;
	if(p != NULL)
	{
		std::cout << "The Stack is Empty!";
		exit(0);
	}
	else
	{
		//取栈顶的元素不需要释放，不是弹栈
		//s->Next = p->Next;
		*e = p->data;
		//free(p);
	}
	return 0;
}

int LinkStack::PushLink_Stack(Link_Stack s, DataType e)
{
	Link_Stack_Node *p = (Link_Stack_Node*)malloc(sizeof(Link_Stack_Node));
	if(p == NULL)
	{
		std::cout << "Malloc Failed!";
		exit(0);
	}
	else
	{
		p->data = e;
		p->Next = s->Next;
		s->Next = p;
	}
	return 0;
}

int LinkStack::PopLink_Stack(Link_Stack s, DataType *e)
{
	Link_Stack_Node *p;
	p = s->Next;
	if(p == NULL)
	{
		std::cout << "Link_Stack is Empty";
		exit(0);
	}
	else
	{
		s->Next = p->Next;
		*e = s->data;
		free(p);
	}
	return 0;
}

int LinkStack::Link_StackLength(Link_Stack s)
{
	Link_Stack_Node *p;
	p = s->Next;
	int i = 0;
	while(p != NULL)
	{
		s->Next = p->Next;
		i++;
	}
	return i;	
}

void LinkStack::ClearLink_Stack(Link_Stack s)
{
	Link_Stack_Node *p, *q;
	p = s->Next;
	while(p != NULL)
	{
		q = p;
		p = p->Next;
		free(q);
	}
}