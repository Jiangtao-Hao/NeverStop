#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElementType;

typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
}LNode;

int  SequentialSearch1(List PtrL,ElementType X);
int  SequentialSearch2(List PtrL,ElementType X);
List MakeEmpty1();
List MakeEmpty2();
int BinarySearch(List PtrL,ElementType X);

int main()
{
	int i;
	int X;
	List L;
	
	printf("不带哨兵的顺序查找\n");
	
	L = MakeEmpty1();
	
	printf("输入元素:");
	do{
		scanf("%d",&L->Data[L->Last+1]);
		L->Last++;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	printf("输入查找的数：");
	scanf("%d",&X);
	printf("Position:%d\n",SequentialSearch1(L,X));
	
	free(L);
	
	getch();

	L = MakeEmpty2();

	printf("输入元素(递增输入):");
	do{
		scanf("%d",&L->Data[L->Last+1]);
		L->Last++;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	printf("带哨兵的顺序查找\n");
	printf("输入查找的数：");
	scanf("%d",&X);
	printf("Position:%d\n",SequentialSearch1(L,X));
	
	printf("二分查找\n");
	printf("输入查找的数：");
	scanf("%d",&X);
	printf("Position:%d",BinarySearch(L,X));
	
	free(L);
}

/*初始化1
 *实现功能：建立空的线性表
 *传入形参：无
 *返回值：线性表指针  
*/
List MakeEmpty1() 
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = -1;//表示线性表中没有元素 
	return PtrL;
}

/*初始化2
 *实现功能：建立空的线性表
 *传入形参：无
 *返回值：线性表指针  
*/
List MakeEmpty2() 
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = 0;//表示线性表中没有元素 
	return PtrL;
}


/*顺序查找  (无"哨兵")
 *函数功能：在Data[0]~Data[n]中查找关键字为X的数据元素 
 *传入形参：线性表指针 PtrL， 关键字 X 
 *返回值：查找成功返回所在单元下标，不成功返回 0 
*/
int SequentialSearch1(List PtrL,ElementType X)
{
	int i;
	
	for(i = PtrL->Last; i > 0 && PtrL->Data[i] != X; i--);
	
	return i;
}

/*顺序查找 (有"哨兵") 
 *函数功能：在Data[1]~Data[n]中查找关键字为X的数据元素 
 *传入形参：线性表指针 PtrL， 关键字 X 
 *返回值：查找成功返回所在单元下标，不成功返回 0 
*/
int  SequentialSearch2(List PtrL,ElementType X)
{
	int i;
	
	PtrL->Data[0] =  X;//建立哨兵 
	for(i = PtrL->Last; PtrL->Data[i] != X; i--);//从后往前遍历查找 
	
	return i; 
}

/*二分查找 (有"哨兵") 
 *函数功能：在Data[1]~Data[n]中查找关键字为X的数据元素 
 *传入形参：线性表指针 PtrL， 关键字 X 
 *返回值：查找成功返回所在单元下标，不成功返回 -1
*/
int BinarySearch(List PtrL,ElementType X)
{
	int left,right,mid;
	int NoFound = -1;
	
	left = 1;
	right = PtrL->Last;
	
	while(left <= right){
		mid = (left + right)/2;//计算中间元素坐标 
		if(X < PtrL->Data[mid]) 	right = mid - 1;//目标在左半部分,调整右边界 
		else if(X > PtrL->Data[mid])	left = mid + 1;// 目标在右半部分，调整左边界 
		else return mid;//目标即在 mid 
	}
	
	return NoFound;
}
