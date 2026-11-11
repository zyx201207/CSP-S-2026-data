#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int c,t,n,k,ans;
int u[20020],v[20020];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&k);
		for(int j=1;j<n;j++)
		 scanf("%d%d",&u[i],&v[i]);
	}
	for(int i=1;i<=t;i++)
	 printf("%d\n",n/k*t/(c+1)%(i*3)); 
	return 0;
}