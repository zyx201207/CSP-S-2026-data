#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long x[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	long long n,d;
	scanf("%d%d",&c,&t);
	while (t--)
	{
		scanf("%lld%lld",&n,&d);
		for (int i=1;i<=n;i++)
		  scanf("%lld",&x[i]);
		long long q=x[2]-x[1];
		if (d>x[n]-x[1])
		{
			printf("%d\n",0);
			continue;
		 }
		if (d<q*2||(x[n]-(x[1]+d-d%q+q))<0)
		{
			printf("%d\n",0);
		}
		else printf("%lld\n",(x[n]-(x[1]+d-d%q+q))/q+1);
	}
	return 0;
}
