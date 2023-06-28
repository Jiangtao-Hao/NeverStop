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
	
	printf("�����ڱ���˳�����\n");
	
	L = MakeEmpty1();
	
	printf("����Ԫ��:");
	do{
		scanf("%d",&L->Data[L->Last+1]);
		L->Last++;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	printf("������ҵ�����");
	scanf("%d",&X);
	printf("Position:%d\n",SequentialSearch1(L,X));
	
	free(L);
	
	getch();

	L = MakeEmpty2();

	printf("����Ԫ��(��������):");
	do{
		scanf("%d",&L->Data[L->Last+1]);
		L->Last++;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	printf("���ڱ���˳�����\n");
	printf("������ҵ�����");
	scanf("%d",&X);
	printf("Position:%d\n",SequentialSearch1(L,X));
	
	printf("���ֲ���\n");
	printf("������ҵ�����");
	scanf("%d",&X);
	printf("Position:%d",BinarySearch(L,X));
	
	free(L);
}

/*��ʼ��1
 *ʵ�ֹ��ܣ������յ����Ա�
 *�����βΣ���
 *����ֵ�����Ա�ָ��  
*/
List MakeEmpty1() 
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = -1;//��ʾ���Ա���û��Ԫ�� 
	return PtrL;
}

/*��ʼ��2
 *ʵ�ֹ��ܣ������յ����Ա�
 *�����βΣ���
 *����ֵ�����Ա�ָ��  
*/
List MakeEmpty2() 
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = 0;//��ʾ���Ա���û��Ԫ�� 
	return PtrL;
}


/*˳�����  (��"�ڱ�")
 *�������ܣ���Data[0]~Data[n]�в��ҹؼ���ΪX������Ԫ�� 
 *�����βΣ����Ա�ָ�� PtrL�� �ؼ��� X 
 *����ֵ�����ҳɹ��������ڵ�Ԫ�±꣬���ɹ����� 0 
*/
int SequentialSearch1(List PtrL,ElementType X)
{
	int i;
	
	for(i = PtrL->Last; i > 0 && PtrL->Data[i] != X; i--);
	
	return i;
}

/*˳����� (��"�ڱ�") 
 *�������ܣ���Data[1]~Data[n]�в��ҹؼ���ΪX������Ԫ�� 
 *�����βΣ����Ա�ָ�� PtrL�� �ؼ��� X 
 *����ֵ�����ҳɹ��������ڵ�Ԫ�±꣬���ɹ����� 0 
*/
int  SequentialSearch2(List PtrL,ElementType X)
{
	int i;
	
	PtrL->Data[0] =  X;//�����ڱ� 
	for(i = PtrL->Last; PtrL->Data[i] != X; i--);//�Ӻ���ǰ�������� 
	
	return i; 
}

/*���ֲ��� (��"�ڱ�") 
 *�������ܣ���Data[1]~Data[n]�в��ҹؼ���ΪX������Ԫ�� 
 *�����βΣ����Ա�ָ�� PtrL�� �ؼ��� X 
 *����ֵ�����ҳɹ��������ڵ�Ԫ�±꣬���ɹ����� -1
*/
int BinarySearch(List PtrL,ElementType X)
{
	int left,right,mid;
	int NoFound = -1;
	
	left = 1;
	right = PtrL->Last;
	
	while(left <= right){
		mid = (left + right)/2;//�����м�Ԫ������ 
		if(X < PtrL->Data[mid]) 	right = mid - 1;//Ŀ������벿��,�����ұ߽� 
		else if(X > PtrL->Data[mid])	left = mid + 1;// Ŀ�����Ұ벿�֣�������߽� 
		else return mid;//Ŀ�꼴�� mid 
	}
	
	return NoFound;
}
