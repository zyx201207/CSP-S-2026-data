#include<bits/stdc++.h>
using namespace std;
#define N 500010
long long n,m;

long long a[N];

long long b[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
//	printf("\n");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%lld ",a[i]);
//	}
//	printf("\n\n");
//	printf("\n");
//	for(int i=1;i<=n;i++)
//	{
//		printf("%lld ",b[i]);
//	}
//	printf("\n\n");
	long long ans=1;
	for(int i=2;i<=n;i++)
	{
		long long l=1;
		long long r=i;
		long long Ans=i;
		while(l<=r)
		{
			long long mid=(l+r)/2;
//			if(i==5)printf("	%lld %lld  %lld %lld",i,mid,(i-mid+1)*a[i],(b[i]-b[mid-1]));
			if((i-mid+1)*a[i]-(b[i]-b[mid-1])<=m)
			{
				r=mid-1;
				Ans=mid;
			}
			else
			{
				l=mid+1;
			}
		}
//		if(i-Ans+1>ans)
//		{
//			printf("%lld %lld  %lld %lld\n",i,Ans,a[i],a[Ans]);
//		}
		ans=max(ans,i-Ans+1);
	}
	printf("%lld",ans);
	return 0;
}
