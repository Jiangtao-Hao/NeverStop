#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;

typedef struct LNode{
	ElementType Data[MAXSIZE];
	int Last;//表示最后一个元素所在的位置 
}LNode;
typedef LNode* List;//定义一个指向Node的指针 

List MakeEmpty(); //初始化一个空线性表
ElementType FinKth(int K,List PtrL);//根据位序K，返回相应元素(按序号查找)
void Find(ElementType X,List PtrL,int *Pst);//在线性表中查找X的位置(按值查找)
void insert(ElementType X,int i,List PtrL);//在位序i前插入一个新元素X
void Delete(int i,List PtrL);//删除指定位序的元素
int Length(List PtrL); //返回线性表L的长度

int main()
{
	int i;
	List L;
	
	L = MakeEmpty();
	
	printf("输入元素:");
	do{
		scanf("%d",&L->Data[L->Last+1]);
		L->Last++;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	printf("查找元素\n请输入位序：");
	int K;
	scanf("%d",&K);
	printf("在该位置上的元素是：%d",FinKth(K,L));
	printf("\n\n");
	
	printf("查找位序\n请输入要查找的数：");
	int X;
	int Pst[MAXSIZE];
	scanf("%d",&X);
	Find(X,L,Pst);
	if(Pst[0] == 0){
		printf("表中未找到该数！");
	}else{
		printf("该数出现的位置下标分别为：");	
		for(i = 1; i <= Pst[0]; i++)
			printf("%d ",Pst[i]);	
	}

	printf("\n\n");
	 
	printf("插入\n请输入要插入的数：");
	scanf("%d",&X);
	printf("请输入插入位置：");
	scanf("%d",&i);
	insert(X,i,L);
	printf("\n");
	
	printf("线性表如下：\n");
	for(i = 0; i <= L->Last; i++)
		printf("%d ",L->Data[i]);
	printf("\n\n");
	
	printf("删除\n请输入要删除的位置：");
	scanf("%d",&i);
	Delete(i,L);
	printf("\n");
	 
	printf("线性表如下：\n");
	for(i = 0; i <= L->Last; i++)
		printf("%d ",L->Data[i]);
	
	free(L);
 }
 
/*初始化
 *实现功能：建立空的线性表
 *传入形参：无
 *返回值：线性表指针  
*/
List MakeEmpty() 
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = -1;//表示线性表中没有元素 
	return PtrL;
}

/*按位序查找 
 *实现功能：根据位序K，返回相应元素
 *传入形参：位序 K，线性表指针 L 
 *返回值：与K相对应的元素 
*/ 
ElementType FinKth(int K,List PtrL)
{
	if(K > PtrL->Last+1 || K < 0){
		printf("该位置无元素！");
	}
	
	return PtrL->Data[K-1];
 }
 

/*按值查找 
 *实现功能：在线性表中查找X出现的位置 
 *传入形参：要查找的数 X，指向线性表的指针 L，位置数组指针 Pst 
 *返回值：无 
*/
void Find(ElementType X,List PtrL,int* Pst)
{
	int p;
	int i = 0;
	
	for(p = 0; p <= PtrL->Last; p++){
		if(PtrL->Data[p] == X){
			Pst[i+1] = p;
			i++;
		}
	} 
	Pst[0] = i; //Pst的第一个位置用来存储该数出现的次数 
	
	return;
 }
 
 /*插入
  *实现功能：在位序i(1<= i <= N+1)前插入一个值为X的新元素
  *传入形参：准备插入的数 X，插入位置 i，线性表指针 L 
  *返回值：无 
 */
void insert(ElementType X,int i,List PtrL)
{
	int j;
	 
	if(PtrL->Last == MAXSIZE -1){		//表空间已满不能插入 
		printf("表满");
		return; 
	} 
	
	//检查插入位置的合法性 
	if(i <= 1 || i > PtrL->Last+2){		//当 i=0时，就人直观观察来说，是没有第0个元素的
		printf("插入位置不合法");		//当 i=Last + 1时，将插入的数放于最后一个数前.
		return;							//当 i= Last + 2,即将插入的数放于表末尾，这是可行的 
	}
	
	for(j = PtrL->Last; j >= i-1; j--)
		PtrL->Data[j+1] = PtrL->Data[j];		//将表中i后的数，逐个从后往前向后挪，以空出插入位置。 
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
 }
 
 /*删除
  *实现功能：删除指定位序的元素
  *传入形参：删除位置 i，线性表指针 L
  *返回值：无 
 */
void Delete(int i,List PtrL)
{
	int j;
	
	//检查删除位置的合法性
	if( i < 1 || i > PtrL->Last + 1){
		printf("不存在第%d个元素",i);
		return;
	}
	
	for(j = i; j <= PtrL->Last; j++)		//将表中i后的数，逐个从前往后向前挪，以覆盖删除位置。
		PtrL->Data[j-1] = PtrL->Data[j];
	PtrL->Last--;
	return;
 }

/*求长度 
 *实现功能：求得线性表的长度 
 *传入形参：线性表指针 L
 *返回值：线性表长度 
*/
int Length(List PtrL)
{
	return PtrL->Last + 1;
 } 

















