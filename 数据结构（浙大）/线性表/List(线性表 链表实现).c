#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;

typedef struct LNode* List;
typedef struct LNode{
	ElementType Data;
	List Next;
}LNode;


void MakeEmpty(List* PtrL); //初始化一个空线性表
List FinKth(int K,List PtrL);//根据位序K，返回相应元素
void Find(ElementType X,List PtrL,List Pst[],int* count);//在线性表中查找X出现的位置
List insert(ElementType X,int i,List PtrL);//在位序i前插入一个新元素X
List Delete(int i,List PtrL);//删除指定位序的元素
int Length(List PtrL); //返回线性表L的长度

int main()
{
	List head = NULL;
	List p;
	List tmp;
	int K;//查找用序号 
	int X;//查找用数字 
	List Pst[Length(head)];//位置数组 
	int i;
	int count;//计数变量 
	
	//初始化 
	MakeEmpty(&head);
	
	//输入 
	printf("input:");
	do{
		tmp = (List)malloc(sizeof(LNode));
		scanf("%d",&tmp->Data);
		
		if(head == NULL){
			head = tmp;
		}else{
			for(p = head;p->Next;p = p->Next);
			p->Next = tmp;
		}
				
		tmp->Next = NULL;
		p = tmp->Next;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	//求表长 
	printf("The length is %d\n",Length(head));
	
	//按序号查找 
	printf("Please input sequence number:");
	scanf("%d",&K);
	FinKth(K,head) == NULL?printf(" K over range\n"):printf("The number at %dth is:%d\n",K,FinKth(K,head)->Data);
	
	//按值查找 
	printf("Please input the number what you want to find:");
	scanf("%d",&X);
	Find(X,head,Pst,&count);
	if(count == 0){
		printf("The number you are looking for does not exist");
	}else{
		printf("The position is:");
		for(i = 0; i < count; i++)
			printf("%d ",Pst[i]);
	}
	printf("\n");

	//插入 
	printf("Please input the number to insert:");
	scanf("%d",&X);
	printf("Please input the position:");
	scanf("%d",&K);
	head = insert(X,K,head);
	printf("output:");
	for(p = head; p != NULL; p = p->Next){
		printf("%d ",p->Data);
	}	
	printf("\n");
	
	//删除 
	printf("Please input the position to delete:");
	scanf("%d",&K);
	head = Delete(K,head);
	
	//输出 
	printf("output:");
	for(p = head; p != NULL; p = p->Next){
		printf("%d ",p->Data);
	}
	
	//释放空间 
	free(head);
}

/*初始化 
 *函数功能：初始化线性表 
 *传入形参：线性表指针 PtrL
 *返回值：无 
*/
void MakeEmpty(List* PtrL)
{
	*PtrL = NULL; //将表指针赋值为NULL，形成一个空表 
}

/*求表长 
 *函数功能：求线性表的表长 
 *传入形参：线性表指针 PtrL
 *返回值：线性表长度 j 
*/
int Length(List PtrL)
{
	List p = PtrL; //p指向表中的第一个结点 
	int j = 0;
	while(p){
		p = p->Next;
		j++;
	}
	return j;
}

/*查找(按序号) 
 *函数功能：按照序号查找 
 *传入形参：准备查找的序号 K，线性表指针 PtrL
 *返回值：找到了，返回指向该结点的指针 p,未找到，返回NULL 
*/
List FinKth(int K,List PtrL)
{
	List p = PtrL;
	int i = 1; //刚开始时，p指向的是第一个结点 
	
	for(p = PtrL; NULL != p && i != K; p = p->Next) //中止条件：找到第K个结点或者遍历完毕 
		i++;
	
	return p;
}

/*查找(按值) 
 *函数功能：按照数值查找 
 *传入形参：准备查找的数 X，线性表指针 PtrL，位置数组Pst，计数变量地址 count 
 *返回值：无 
*/
void Find(ElementType X,List PtrL,List Pst[],int* count)
{
	List p;
	int i = 0;
	
	for(p = PtrL; NULL != p; p = p->Next){//为了将最后一个数也比较上，所以截至条件为“NULL != p” 
		if(p->Data == X){ 
			Pst[i] = p;
			i++;
		}
	}
	*count = i;
}

/*插入
 *函数功能：在位序i前(在位序i-1后)插入一个新元素X
 *传入参数：准备插入的数 X，插入位置 i，线性表指针 L
 *返回值： 线性表指针 PtrL
*/
List insert(ElementType X,int i,List PtrL)
{
	List s,tmp;
	
	if(i == 1){//如果插入位置是在第1个之前，即让新节点成为第一个结点 
		s = (List)malloc(sizeof(LNode));
		s->Next = PtrL;//令s->next指向原链表中第一个元素 
		PtrL = s;//使PtrL指向s,s成为第一个元素 
		
		s->Data = X;
	}else{
		tmp = FinKth(i-1,PtrL);//在第i个元素之前插入，需要更改第i-1元素的next，所以需要找到第i-1个元素的指针 
		s = (List)malloc(sizeof(LNode));
		s->Next = tmp->Next;//使s->next同样指向第i个元素(连接好后面) 
		tmp->Next = s;//使第i-1个元素指向s(连接好前面) 
		
		s->Data = X;
	}
	
	return PtrL;
 }

/*插入
 *函数功能：删除在位序i(在位序i-1后)的结点 
 *传入参数：插入位置 i，线性表指针 L
 *返回值：新线性表指针 L
*/
List Delete(int i,List PtrL)
{
	List s,tmp;
	
	if(i == 1){//如果删除位置是在第1个，即让第二个结点成为第一个结点 
		s = PtrL;// 将要删除的结点地址暂存 
		PtrL = PtrL->Next;//建立新的链关系 
		
		free(s);//释放空间 
	}else{
		tmp = FinKth(i-1,PtrL);//要删除第i个元素，需要更改第i-1元素的next，所以需要找到第i-1个元素的指针 
		s = tmp->Next;//删除结点地址暂存 
		tmp->Next = s->Next;//建立新的链关系 
		
		free(s);//释放空间 
	}
	
	return PtrL;
 }


