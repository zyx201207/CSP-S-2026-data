#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],sum[1000010];
bool check(long long mid)
{
	long long j=0,k=0,x=0;
	for(long long i=1;i+mid-1<=n;i++)
	{
		j=i+mid-1;
		k=sum[j-1]-sum[i-1];
		x=(mid-1)*a[j]-k;
		if(x<=m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	memset(sum,0,sizeof(sum));
	for(long long i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long mid=0,ans=1,l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
