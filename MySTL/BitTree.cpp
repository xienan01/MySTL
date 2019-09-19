#include "BitTree.h"
#include  "iostream"



BitTree::BitTree()
{

}

BitTree::~BitTree()
{

}


void BitTree::OinitBitTree(BitTree_t *T)
{
	*T = NULL;
}

//���ٶ�����
void BitTree::DestroyBitTree(BitTree_t *T)
{
	if(*T)
	{
		if((*T)->lChild)
		{
			DestroyBitTree(&((*T)->lChild));
		}
		if((*T)->rChild)
		{
			DestroyBitTree(&((*T)->rChild));
		}
	}
}

//����������
void BitTree::CreateBitTree(BitTree_t *T)
{
	DataType ch;
	scanf("%c", ch);
	if(ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BitTree_t)malloc(sizeof(BitNode)); 
		if(*T != NULL)
		{
			(*T)->data = ch;
			//������������
			CreateBitTree(&((*T)->lChild));  
			CreateBitTree(&((*T)->rChild));
		}
		else
		{
			exit(0);
		}
	}
}

//������������� LR =0,����Ϊ��������LPR=1������Ϊ������
int BitTree::InsertBitTree(BitTree_t T, int LR, BitTree_t t)
{
	if(T)
	{
		if(LR ==0)
		{
			// ԭ����T�����������t��������
			t->lChild = T->lChild;
			T->lChild = t;
		}
		else
		{
			t->rChild = T->rChild;
			T->rChild = t;
		}
	}
	return 0;
}

//���ض�����e�����ӽڵ��Ԫ��ֵ
DataType BitTree::LeftChild(BitTree_t T, DataType e)
{
	BitTree_t p;
	if(T)
	{
		p = Point(T,e);
		if(p && p->lChild)
		{
			return T->lChild->data;
		}
	}
	return;
}

//���ض������Һ��ӽڵ��Ԫ��ֵ
DataType BitTree::RightChild(BitTree_t T, DataType e)
{
	BitTree_t p;
	if(T)
	{
		p = Point(T,e); // �ҵ�Ԫ��Ϊe�Ľڵ�
		if(p && p->rChild)
		{
			return T->rChild->data;
		}
	}
	return;
}

//���ض����������ڵ��ָ��
BitTree_t BitTree::Point(BitTree_t T, DataType e)
{

}

//ɾ���������� LR =0ɾ����������LR = 1ɾ��������
int BitTree::DeleteBitTree(BitTree_t T, int LR)
{
	if(T)
	{
		if(LR == 0)
		{
			DestroyBitTree(&(T->lChild));
		}
		if(LR ==1)
		{
			DestroyBitTree(&(T->rChild));
		}
	}
	return 0;
}

void BitTree::PreOrderTraverse(BitTree_t T)
{
	if(T)
	{
		printf("%2c",T->data);
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}
}

void BitTree::InOrderTraverse(BitTree_t T)
{
	if(T)
	{
		PreOrderTraverse(T->lChild);
		printf("%2c",T->data);
		PreOrderTraverse(T->rChild);
	}
}

void BitTree::PostOrderTraverse(BitTree_t T)
{
	if(T)
	{
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
		printf("%2c",T->data);
	}
}