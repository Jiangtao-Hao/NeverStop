#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXN 10
#define MAXK 1e7

clock_t start;
clock_t stop;
double duration;

double f1(int n,double a[],double x);//一般多项式计算方法 
double f2(int n,double a[],double x);//秦九韶算法 
void timeMeasure(double (*f)(int n,double a[],double x),double a[]);

int main(){
	int i;
	double a[MAXN];
	
	for( i = 0; i < MAXN; i++)
		a[i] = (double)i;
	
	timeMeasure(f1,a);
	timeMeasure(f2,a);
}

void timeMeasure(double (*f)(int n,double a[],double x),double a[])
{
	int i;
	
	start = clock();
	for(i = 0; i <= MAXK; i++)
		f(MAXN-1,a,1.2);
	stop = clock();
	duration = (double)(stop - start)/CLK_TCK/MAXK;
	printf("ticks = %f\n",(double)(stop - start));
	printf("duration = %5.2e\n",duration);
}

double f1(int n,double a[],double x)
{
	int i;
	double p = a[0];
	for(i = 1;i <= n;i++)					//循环了n次 
		p += (a[i] * pow(x,i)); 			//每次循环做了（1 + i-1  ）次乘法，则总乘法数为（1+2+3+...+n）=(n^2+n)/2 
	return p;								//T(n) = C1*n^2+C2*n
}

double f2(int n,double a[],double x)
{
	int i;
	double p = a[n];
	for(i = n; i > 0; i--)					//循环了n次 
		p = a[i-1] + x*a[i];				//每次循环做了1次乘法 
	return p;								//T(n) = C*n 
}

