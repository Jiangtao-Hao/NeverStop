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
	printf("是否运行迭代程序？(运行：Y，不运行：N)");
	scanf("%c",&ch);
	if(ch == 'Y')
		printfM(N);//最大显示取决于栈空间的大小 
}
