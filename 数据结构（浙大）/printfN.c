#include <stdio.h>

void printfN(int N){
	int i;
	for(i = 1; i <= N; i++){
		printf("%d\n",i);
	}
}

void printfM(int N){
	if(N)
		printfM(N-1);
	printf("%d\n",N);
}

int main()
{
	int N;
	char ch;
	scanf("%d",&N);
	
	printfN(N);
	getchar();
	printf("�Ƿ����е�������(���У�Y�������У�N)");
	scanf("%c",&ch);
	if(ch == 'Y')
		printfM(N);//�����ʾȡ����ջ�ռ�Ĵ�С 
}
