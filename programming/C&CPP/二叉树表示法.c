#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <iostream>
//二叉链表 
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //左孩子 右孩子
}BiTNode, *BiTree;

//三叉链表
typedef struct TriTNode 
{
	int data;
	//左右孩子指针
	struct TriTNode *lchild, *rchild;
	struct TriTNode *parent;
}TriTNode, *TriTree;


//双亲链表
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int *parent; //指向双亲的指针
	char LRTag; //左右孩子标志域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[MAX_TREE_SIZE]; //因为节点之间是分散的，需要把节点存储到数组中
	int num_node;  //节点数目
	int root; //根结点的位置 //注意此域存储的是父亲节点在数组的下标
}BPTree;


void PreOrder(BiTNode *T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

/*
       1
	2     3 
  4      5
 */
//1 遍历算法 3种
void InOrder(BiTNode *T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTNode *T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%d ", T->data);
	}
}

//2 计算叶子结点
int g_count = 0;
void CountLeaf(BiTNode *T) 
{
	if (T != NULL)
	{
		CountLeaf(T->lchild);
		
		CountLeaf(T->rchild);

		if (T->lchild == NULL && T->rchild == NULL)
		{
			g_count ++;
		}
	}
}

void CountLeaf2(BiTNode *T, int *ncount) 
{
	if (T != NULL)
	{
		CountLeaf2(T->lchild, ncount);

		CountLeaf2(T->rchild, ncount);

		if (T->lchild == NULL && T->rchild == NULL)
		{
			 (*ncount)++;
		}
	}
}
//3 计算深度
int Depth(BiTNode* T)
{
	int depthval = 0,depthR = 0, depthL = 0;
	if(T = NULL)
	{
		depthval = 0;
		return depthval; 
	}
	depthL = Depth(T->lchild);
	depthR = Depth(T->lchild);
	depthval = 1 + ((depthL>depthR)?depthL:depthR);
	return depthval; 
}
int main()
{
	BiTNode b1, b2, b3, b4, b5;
	memset(&b1, 0, sizeof(BiTNode));
	memset(&b2, 0, sizeof(BiTNode));
	memset(&b3, 0, sizeof(BiTNode));
	memset(&b4, 0, sizeof(BiTNode));
	memset(&b5, 0, sizeof(BiTNode));
	b1.data = 1;
	b2.data = 2;
	b3.data = 3;
	b4.data = 4;
	b5.data = 5;

	//构建树关系
	b1.lchild = &b2;
	b1.rchild = &b3;
	b2.lchild = &b4;
	b3.lchild = &b5;
	printf("\n先根遍历");
	PreOrder(&b1);
	printf("\n中根遍历");
	InOrder(&b1);

	printf("\n后根遍历");
	PostOrder(&b1);

	{
		int ncoutn = 0;
		CountLeaf2(&b1, &ncoutn);
		printf("\n叶子结点个数:%d", ncoutn);
	}
	//求解深度
	std::cout<<Depth(&b1)<<std::endl;
	system("pause");
	return 0;
}