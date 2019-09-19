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

//销毁二叉树
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

//创建二叉树
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
			//构造左右子树
			CreateBitTree(&((*T)->lChild));  
			CreateBitTree(&((*T)->rChild));
		}
		else
		{
			exit(0);
		}
	}
}

//二叉树插入操作 LR =0,插入为左子树，LPR=1，插入为右子树
int BitTree::InsertBitTree(BitTree_t T, int LR, BitTree_t t)
{
	if(T)
	{
		if(LR ==0)
		{
			// 原来的T的左子树变成t的左子树
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

//返回二叉树e的左孩子节点的元素值
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

//返回二叉树右孩子节点的元素值
DataType BitTree::RightChild(BitTree_t T, DataType e)
{
	BitTree_t p;
	if(T)
	{
		p = Point(T,e); // 找到元素为e的节点
		if(p && p->rChild)
		{
			return T->rChild->data;
		}
	}
	return;
}

//返回二叉树给定节点的指针
BitTree_t BitTree::Point(BitTree_t T, DataType e)
{

}

//删除子树操作 LR =0删除左子树，LR = 1删除右子树
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