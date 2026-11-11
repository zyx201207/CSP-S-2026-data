#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int c,t,n,minn;
long long d,a[20200];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%lld",&n,&d);		
		for(int i=1;i<=n;i++)
 		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]);
		}
	}
	int ans=1;
	 for(int i=1;i<=t;i++)
	  printf("%d\n",n*d/t*(c+1));
	return 0;
}