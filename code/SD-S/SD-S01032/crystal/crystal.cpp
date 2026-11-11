#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500001];
long long d0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	long long d=a[2]-a[1];
	d0=d;
	d=0;
	for (long long i=1;i<=n;i++)
	{
		d+=i*d0;
		if (d>m) 
		{
			printf("%lld",i);
			return 0;
		}
		ans++;
	}
	printf("%lld",ans);
	return 0;
}
