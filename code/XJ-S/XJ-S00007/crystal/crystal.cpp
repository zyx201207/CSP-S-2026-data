#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
bool check(long long x)
{
	for(long long i=1;i+x-1<=n;i++)
	{
		long long l=i,r=i+x-1;
		long long tmp=a[r]*(r-l+1)-(s[r]-s[l-1]);
		if(tmp<=m)
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
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	long long l=0,r=n,best=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			best=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld",best);
	return 0;
}

