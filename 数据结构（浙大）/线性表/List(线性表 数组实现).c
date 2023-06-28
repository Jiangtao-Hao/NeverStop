#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElementType;

typedef struct LNode{
	ElementType Data[MAXSIZE];
	int Last;//��ʾ���һ��Ԫ�����ڵ�λ�� 
}LNode;
typedef LNode* List;//����һ��ָ��Node��ָ�� 

List MakeEmpty(); //��ʼ��һ�������Ա�
ElementType FinKth(int K,List PtrL);//����λ��K��������ӦԪ��(����Ų���)
void Find(ElementType X,List PtrL,int *Pst);//�����Ա��в���X��λ��(��ֵ����)
void insert(ElementType X,int i,List PtrL);//��λ��iǰ����һ����Ԫ��X
void Delete(int i,List PtrL);//ɾ��ָ��λ���Ԫ��
int Length(List PtrL); //�������Ա�L�ĳ���

int main()
{
	int i;
	List L;
	
	L = MakeEmpty();
	
	printf("����Ԫ��:");
	do{
		scanf("%d",&L->Data[L->Last+1]);
		L->Last++;
		
		if(getchar() == '\n')
			break;
	}while(1);
	
	printf("����Ԫ��\n������λ��");
	int K;
	scanf("%d",&K);
	printf("�ڸ�λ���ϵ�Ԫ���ǣ�%d",FinKth(K,L));
	printf("\n\n");
	
	printf("����λ��\n������Ҫ���ҵ�����");
	int X;
	int Pst[MAXSIZE];
	scanf("%d",&X);
	Find(X,L,Pst);
	if(Pst[0] == 0){
		printf("����δ�ҵ�������");
	}else{
		printf("�������ֵ�λ���±�ֱ�Ϊ��");	
		for(i = 1; i <= Pst[0]; i++)
			printf("%d ",Pst[i]);	
	}

	printf("\n\n");
	 
	printf("����\n������Ҫ���������");
	scanf("%d",&X);
	printf("���������λ�ã�");
	scanf("%d",&i);
	insert(X,i,L);
	printf("\n");
	
	printf("���Ա����£�\n");
	for(i = 0; i <= L->Last; i++)
		printf("%d ",L->Data[i]);
	printf("\n\n");
	
	printf("ɾ��\n������Ҫɾ����λ�ã�");
	scanf("%d",&i);
	Delete(i,L);
	printf("\n");
	 
	printf("���Ա����£�\n");
	for(i = 0; i <= L->Last; i++)
		printf("%d ",L->Data[i]);
	
	free(L);
 }
 
/*��ʼ��
 *ʵ�ֹ��ܣ������յ����Ա�
 *�����βΣ���
 *����ֵ�����Ա�ָ��  
*/
List MakeEmpty() 
{
	List PtrL;
	PtrL = (List)malloc(sizeof(LNode));
	PtrL->Last = -1;//��ʾ���Ա���û��Ԫ�� 
	return PtrL;
}

/*��λ����� 
 *ʵ�ֹ��ܣ�����λ��K��������ӦԪ��
 *�����βΣ�λ�� K�����Ա�ָ�� L 
 *����ֵ����K���Ӧ��Ԫ�� 
*/ 
ElementType FinKth(int K,List PtrL)
{
	if(K > PtrL->Last+1 || K < 0){
		printf("��λ����Ԫ�أ�");
	}
	
	return PtrL->Data[K-1];
 }
 

/*��ֵ���� 
 *ʵ�ֹ��ܣ������Ա��в���X���ֵ�λ�� 
 *�����βΣ�Ҫ���ҵ��� X��ָ�����Ա��ָ�� L��λ������ָ�� Pst 
 *����ֵ���� 
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
	Pst[0] = i; //Pst�ĵ�һ��λ�������洢�������ֵĴ��� 
	
	return;
 }
 
 /*����
  *ʵ�ֹ��ܣ���λ��i(1<= i <= N+1)ǰ����һ��ֵΪX����Ԫ��
  *�����βΣ�׼��������� X������λ�� i�����Ա�ָ�� L 
  *����ֵ���� 
 */
void insert(ElementType X,int i,List PtrL)
{
	int j;
	 
	if(PtrL->Last == MAXSIZE -1){		//��ռ��������ܲ��� 
		printf("����");
		return; 
	} 
	
	//������λ�õĺϷ��� 
	if(i <= 1 || i > PtrL->Last+2){		//�� i=0ʱ������ֱ�۹۲���˵����û�е�0��Ԫ�ص�
		printf("����λ�ò��Ϸ�");		//�� i=Last + 1ʱ������������������һ����ǰ.
		return;							//�� i= Last + 2,��������������ڱ�ĩβ�����ǿ��е� 
	}
	
	for(j = PtrL->Last; j >= i-1; j--)
		PtrL->Data[j+1] = PtrL->Data[j];		//������i�����������Ӻ���ǰ���Ų���Կճ�����λ�á� 
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
 }
 
 /*ɾ��
  *ʵ�ֹ��ܣ�ɾ��ָ��λ���Ԫ��
  *�����βΣ�ɾ��λ�� i�����Ա�ָ�� L
  *����ֵ���� 
 */
void Delete(int i,List PtrL)
{
	int j;
	
	//���ɾ��λ�õĺϷ���
	if( i < 1 || i > PtrL->Last + 1){
		printf("�����ڵ�%d��Ԫ��",i);
		return;
	}
	
	for(j = i; j <= PtrL->Last; j++)		//������i������������ǰ������ǰŲ���Ը���ɾ��λ�á�
		PtrL->Data[j-1] = PtrL->Data[j];
	PtrL->Last--;
	return;
 }

/*�󳤶� 
 *ʵ�ֹ��ܣ�������Ա�ĳ��� 
 *�����βΣ����Ա�ָ�� L
 *����ֵ�����Ա��� 
*/
int Length(List PtrL)
{
	return PtrL->Last + 1;
 } 

















