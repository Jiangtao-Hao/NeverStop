#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;

typedef struct LNode* List;
typedef struct LNode{
	ElementType Data;
	List Next;
}LNode;


void MakeEmpty(List* PtrL); //��ʼ��һ�������Ա�
List FinKth(int K,List PtrL);//����λ��K��������ӦԪ��
void Find(ElementType X,List PtrL,List Pst[],int* count);//�����Ա��в���X���ֵ�λ��
List insert(ElementType X,int i,List PtrL);//��λ��iǰ����һ����Ԫ��X
List Delete(int i,List PtrL);//ɾ��ָ��λ���Ԫ��
int Length(List PtrL); //�������Ա�L�ĳ���

int main()
{
	List head = NULL;
	List p;
	List tmp;
	int K;//��������� 
	int X;//���������� 
	List Pst[Length(head)];//λ������ 
	int i;
	int count;//�������� 
	
	//��ʼ�� 
	MakeEmpty(&head);
	
	//���� 
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
	
	//��� 
	printf("The length is %d\n",Length(head));
	
	//����Ų��� 
	printf("Please input sequence number:");
	scanf("%d",&K);
	FinKth(K,head) == NULL?printf(" K over range\n"):printf("The number at %dth is:%d\n",K,FinKth(K,head)->Data);
	
	//��ֵ���� 
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

	//���� 
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
	
	//ɾ�� 
	printf("Please input the position to delete:");
	scanf("%d",&K);
	head = Delete(K,head);
	
	//��� 
	printf("output:");
	for(p = head; p != NULL; p = p->Next){
		printf("%d ",p->Data);
	}
	
	//�ͷſռ� 
	free(head);
}

/*��ʼ�� 
 *�������ܣ���ʼ�����Ա� 
 *�����βΣ����Ա�ָ�� PtrL
 *����ֵ���� 
*/
void MakeEmpty(List* PtrL)
{
	*PtrL = NULL; //����ָ�븳ֵΪNULL���γ�һ���ձ� 
}

/*��� 
 *�������ܣ������Ա�ı� 
 *�����βΣ����Ա�ָ�� PtrL
 *����ֵ�����Ա��� j 
*/
int Length(List PtrL)
{
	List p = PtrL; //pָ����еĵ�һ����� 
	int j = 0;
	while(p){
		p = p->Next;
		j++;
	}
	return j;
}

/*����(�����) 
 *�������ܣ�������Ų��� 
 *�����βΣ�׼�����ҵ���� K�����Ա�ָ�� PtrL
 *����ֵ���ҵ��ˣ�����ָ��ý���ָ�� p,δ�ҵ�������NULL 
*/
List FinKth(int K,List PtrL)
{
	List p = PtrL;
	int i = 1; //�տ�ʼʱ��pָ����ǵ�һ����� 
	
	for(p = PtrL; NULL != p && i != K; p = p->Next) //��ֹ�������ҵ���K�������߱������ 
		i++;
	
	return p;
}

/*����(��ֵ) 
 *�������ܣ�������ֵ���� 
 *�����βΣ�׼�����ҵ��� X�����Ա�ָ�� PtrL��λ������Pst������������ַ count 
 *����ֵ���� 
*/
void Find(ElementType X,List PtrL,List Pst[],int* count)
{
	List p;
	int i = 0;
	
	for(p = PtrL; NULL != p; p = p->Next){//Ϊ�˽����һ����Ҳ�Ƚ��ϣ����Խ�������Ϊ��NULL != p�� 
		if(p->Data == X){ 
			Pst[i] = p;
			i++;
		}
	}
	*count = i;
}

/*����
 *�������ܣ���λ��iǰ(��λ��i-1��)����һ����Ԫ��X
 *���������׼��������� X������λ�� i�����Ա�ָ�� L
 *����ֵ�� ���Ա�ָ�� PtrL
*/
List insert(ElementType X,int i,List PtrL)
{
	List s,tmp;
	
	if(i == 1){//�������λ�����ڵ�1��֮ǰ�������½ڵ��Ϊ��һ����� 
		s = (List)malloc(sizeof(LNode));
		s->Next = PtrL;//��s->nextָ��ԭ�����е�һ��Ԫ�� 
		PtrL = s;//ʹPtrLָ��s,s��Ϊ��һ��Ԫ�� 
		
		s->Data = X;
	}else{
		tmp = FinKth(i-1,PtrL);//�ڵ�i��Ԫ��֮ǰ���룬��Ҫ���ĵ�i-1Ԫ�ص�next��������Ҫ�ҵ���i-1��Ԫ�ص�ָ�� 
		s = (List)malloc(sizeof(LNode));
		s->Next = tmp->Next;//ʹs->nextͬ��ָ���i��Ԫ��(���Ӻú���) 
		tmp->Next = s;//ʹ��i-1��Ԫ��ָ��s(���Ӻ�ǰ��) 
		
		s->Data = X;
	}
	
	return PtrL;
 }

/*����
 *�������ܣ�ɾ����λ��i(��λ��i-1��)�Ľ�� 
 *�������������λ�� i�����Ա�ָ�� L
 *����ֵ�������Ա�ָ�� L
*/
List Delete(int i,List PtrL)
{
	List s,tmp;
	
	if(i == 1){//���ɾ��λ�����ڵ�1�������õڶ�������Ϊ��һ����� 
		s = PtrL;// ��Ҫɾ���Ľ���ַ�ݴ� 
		PtrL = PtrL->Next;//�����µ�����ϵ 
		
		free(s);//�ͷſռ� 
	}else{
		tmp = FinKth(i-1,PtrL);//Ҫɾ����i��Ԫ�أ���Ҫ���ĵ�i-1Ԫ�ص�next��������Ҫ�ҵ���i-1��Ԫ�ص�ָ�� 
		s = tmp->Next;//ɾ������ַ�ݴ� 
		tmp->Next = s->Next;//�����µ�����ϵ 
		
		free(s);//�ͷſռ� 
	}
	
	return PtrL;
 }


