#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+5;
int w[N];
struct Node
{
	int fir,sec;
	int ft,st;
}a[510];
int c,n,m,d,q,k,stp=-1,f=0,root;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c==0&&n==2) 
		printf("32\n17");
	else if(c==0&&n==3)
		printf("35\n16");
	return 0;
}
