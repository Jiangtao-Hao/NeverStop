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
		ThisSum += A[i];		//向右累加 
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;	//发现更大和则更新当前结果 
		}else if(ThisSum < 0){	//如果当前子列和为负 
			ThisSum = 0;		//则不可能使后面的部分和增大，抛弃之 
		}
	}
	
	return MaxSum;
}
 
int MaxSubseqSum2(int A1[],int N1)
{
	int MaxLeft = 0;//左最大 
	int MaxRight = 0;//右最大
	int MaxCross = 0;//跨界最大
	int ThisSum = 0;//求跨边界最大时的临时变量 
	int MaxCrossLeft = 0;//跨边界最大的左子列和
	int MaxCrossRight = 0;// 跨边界最大的右子列和
	int i,j;
	int A[N1 + N1%2];// 当数字个数为奇数个数时，申请N+1个空间
	int N;
	
	if(N1%2 != 0){	//当N为奇数时 
		for(i = 0; i < N1; i++)
			A[i] = A1[i];
		A[N1] = 0;	//将最后一个空间赋值为0，不影响最后结果 
		N = N1 + N1%2;
	}else{			//当N为偶数时 
		for(i = 0; i < N1; i++)
			A[i] = A1[i];
		N = N1;
	}
	
	
	//将序列对半分：1.申请两组空间 2.进行赋值 
	int ALeft[N/2],ARight[N/2]; 
	
	for(i = 0; i <= N/2;i++){
		ALeft[i] = A[i];
		ARight[i] = A[N/2 + i];
	}
		
	if(N == 2){ //当数字个数对半分，直到只剩两个数字时
		A[0] > 0? MaxLeft = A[0]:MaxLeft;  //左最大值赋值为第一个数 
		A[1] > 0? MaxRight = A[1]:MaxRight;//右最大值赋值为第二个数 
	}else{		//当数字个数仍大于2时 
		MaxLeft = MaxSubseqSum2(ALeft,N/2);//左最大值即求左半部分的最大值，与本函数研究问题一致，进行递归 
		MaxRight = MaxSubseqSum2(ARight,N/2);//右最大值，同上左最大值的处理 
		
		ThisSum = 0;
		for(i = N/2-1; i >=0; i--){
			ThisSum += A[i];
		ThisSum > MaxCrossLeft? MaxCrossLeft = ThisSum:MaxCrossLeft;//求得跨边界最大的左子列和
		}//从中间向左找最大 

		ThisSum = 0;
		for(i = N/2; i < N; i++){
			ThisSum += A[i];
		ThisSum > MaxCrossRight? MaxCrossRight = ThisSum:MaxCrossRight;//求得跨边界最大的右子列和
		}//从中间向右找最大
		MaxCross = MaxCrossLeft + MaxCrossRight;//跨界最大=左子列和+右子列和 
	}
	
	return MaxLeft > MaxRight?(MaxLeft > MaxCross?MaxLeft:MaxCross):(MaxRight > MaxCross?MaxRight:MaxCross);//比较并得出该部分的最大子列和 
}

int MaxSubseqSum1(int A[],int N)
{
	int ThisSum;
	int MaxSum = 0;
	int i,j;
	
	for(i = 0; i < N; i++){		//i是子列左端位置 
		
		ThisSum = 0;			//求一个子列和之前，将上一个子列和归零 
	
		for(j = i; j < N; j++){ //j是子列右端 
			ThisSum += A[j];	 
			ThisSum > MaxSum? MaxSum = ThisSum:MaxSum;		
		}						//一次i循环结束，就将“以同一个位置作为左端的所有子列”全部比较完毕 
	}
	
	return MaxSum;
}
