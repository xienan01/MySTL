#ifndef BITTREE_H
#define BITTREE_H

typedef int DataType; 

//定义一个二叉树
typedef struct BitTreeNode
{
	DataType data;
	BitTreeNode *lChild;
	BitTreeNode *rChild;
} *BitTree_t,BitNode;

// 二叉树
class BitTree
{
public:
	BitTree();
	~BitTree();

public:
	//初始化二叉树
	void OinitBitTree(BitTree_t *T);
	//销毁二叉树
	void DestroyBitTree(BitTree_t *T);
	//创建二叉树
	void CreateBitTree(BitTree_t *T);
	//二叉树插入操作 LR =0,插入为左子树，LPR=1，插入为右子树
	int InsertBitTree(BitTree_t T, int LR, BitTree_t t);
	//返回二叉树左孩子节点的元素值
	DataType LeftChild(BitTree_t T, DataType e);
	//返回二叉树右孩子节点的元素值
	DataType RightChild(BitTree_t T, DataType e);
	//返回二叉树给定节点的指针
	BitTree_t Point(BitTree_t T,DataType e);
	//删除子树操作 LR =0删除左子树，LR = 1删除右子树
	int DeleteBitTree(BitTree_t T, int LR);

	///递归遍历二叉树 先序遍历(DLR) 中序遍历(LDR) 后序遍历(LRD)
	void PreOrderTraverse(BitTree_t T);
	void InOrderTraverse(BitTree_t T);
	void PostOrderTraverse(BitTree_t T);
	//非递归遍历


};

#endif