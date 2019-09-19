#ifndef BITTREE_H
#define BITTREE_H

typedef int DataType; 

//����һ��������
typedef struct BitTreeNode
{
	DataType data;
	BitTreeNode *lChild;
	BitTreeNode *rChild;
} *BitTree_t,BitNode;

// ������
class BitTree
{
public:
	BitTree();
	~BitTree();

public:
	//��ʼ��������
	void OinitBitTree(BitTree_t *T);
	//���ٶ�����
	void DestroyBitTree(BitTree_t *T);
	//����������
	void CreateBitTree(BitTree_t *T);
	//������������� LR =0,����Ϊ��������LPR=1������Ϊ������
	int InsertBitTree(BitTree_t T, int LR, BitTree_t t);
	//���ض��������ӽڵ��Ԫ��ֵ
	DataType LeftChild(BitTree_t T, DataType e);
	//���ض������Һ��ӽڵ��Ԫ��ֵ
	DataType RightChild(BitTree_t T, DataType e);
	//���ض����������ڵ��ָ��
	BitTree_t Point(BitTree_t T,DataType e);
	//ɾ���������� LR =0ɾ����������LR = 1ɾ��������
	int DeleteBitTree(BitTree_t T, int LR);

	///�ݹ���������� �������(DLR) �������(LDR) �������(LRD)
	void PreOrderTraverse(BitTree_t T);
	void InOrderTraverse(BitTree_t T);
	void PostOrderTraverse(BitTree_t T);
	//�ǵݹ����


};

#endif