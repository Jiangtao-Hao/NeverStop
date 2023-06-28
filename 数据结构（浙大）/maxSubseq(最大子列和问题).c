#include <stdio.h>

#define MaxN 7

int MaxSubseqSum1(int A[],int N);
int MaxSubseqSum2(int A1[],int N1);
int MaxSubseqSum3(int A[],int N);

int main()
{
	int A[MaxN] = {4,-3,5,-2,-1,2,6};
	
	printf("MaxSum1 = %d\n",MaxSubseqSum1(A,MaxN));
	printf("MaxSum2 = %d\n",MaxSubseqSum2(A,MaxN));
	printf("MaxSum3 = %d",MaxSubseqSum3(A,MaxN));
 }
 
int MaxSubseqSum3(int A[],int N)
{
	int i;
	int ThisSum = 0;
	int MaxSum = 0;
	
	for(i = 0; i < N; i++){
		ThisSum += A[i];		//�����ۼ� 
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;	//���ָ��������µ�ǰ��� 
		}else if(ThisSum < 0){	//�����ǰ���к�Ϊ�� 
			ThisSum = 0;		//�򲻿���ʹ����Ĳ��ֺ���������֮ 
		}
	}
	
	return MaxSum;
}
 
int MaxSubseqSum2(int A1[],int N1)
{
	int MaxLeft = 0;//����� 
	int MaxRight = 0;//�����
	int MaxCross = 0;//������
	int ThisSum = 0;//���߽����ʱ����ʱ���� 
	int MaxCrossLeft = 0;//��߽����������к�
	int MaxCrossRight = 0;// ��߽����������к�
	int i,j;
	int A[N1 + N1%2];// �����ָ���Ϊ��������ʱ������N+1���ռ�
	int N;
	
	if(N1%2 != 0){	//��NΪ����ʱ 
		for(i = 0; i < N1; i++)
			A[i] = A1[i];
		A[N1] = 0;	//�����һ���ռ丳ֵΪ0����Ӱ������� 
		N = N1 + N1%2;
	}else{			//��NΪż��ʱ 
		for(i = 0; i < N1; i++)
			A[i] = A1[i];
		N = N1;
	}
	
	
	//�����ж԰�֣�1.��������ռ� 2.���и�ֵ 
	int ALeft[N/2],ARight[N/2]; 
	
	for(i = 0; i <= N/2;i++){
		ALeft[i] = A[i];
		ARight[i] = A[N/2 + i];
	}
		
	if(N == 2){ //�����ָ����԰�֣�ֱ��ֻʣ��������ʱ
		A[0] > 0? MaxLeft = A[0]:MaxLeft;  //�����ֵ��ֵΪ��һ���� 
		A[1] > 0? MaxRight = A[1]:MaxRight;//�����ֵ��ֵΪ�ڶ����� 
	}else{		//�����ָ����Դ���2ʱ 
		MaxLeft = MaxSubseqSum2(ALeft,N/2);//�����ֵ������벿�ֵ����ֵ���뱾�����о�����һ�£����еݹ� 
		MaxRight = MaxSubseqSum2(ARight,N/2);//�����ֵ��ͬ�������ֵ�Ĵ��� 
		
		ThisSum = 0;
		for(i = N/2-1; i >=0; i--){
			ThisSum += A[i];
		ThisSum > MaxCrossLeft? MaxCrossLeft = ThisSum:MaxCrossLeft;//��ÿ�߽����������к�
		}//���м���������� 

		ThisSum = 0;
		for(i = N/2; i < N; i++){
			ThisSum += A[i];
		ThisSum > MaxCrossRight? MaxCrossRight = ThisSum:MaxCrossRight;//��ÿ�߽����������к�
		}//���м����������
		MaxCross = MaxCrossLeft + MaxCrossRight;//������=�����к�+�����к� 
	}
	
	return MaxLeft > MaxRight?(MaxLeft > MaxCross?MaxLeft:MaxCross):(MaxRight > MaxCross?MaxRight:MaxCross);//�Ƚϲ��ó��ò��ֵ�������к� 
}

int MaxSubseqSum1(int A[],int N)
{
	int ThisSum;
	int MaxSum = 0;
	int i,j;
	
	for(i = 0; i < N; i++){		//i���������λ�� 
		
		ThisSum = 0;			//��һ�����к�֮ǰ������һ�����к͹��� 
	
		for(j = i; j < N; j++){ //j�������Ҷ� 
			ThisSum += A[j];	 
			ThisSum > MaxSum? MaxSum = ThisSum:MaxSum;		
		}						//һ��iѭ���������ͽ�����ͬһ��λ����Ϊ��˵��������С�ȫ���Ƚ���� 
	}
	
	return MaxSum;
}
