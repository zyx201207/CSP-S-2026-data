#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	vector<long long>a(n+1,0);
	vector<long long>sum(n+1,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	auto check=[&sum,&a,&n,&m](int len)
	{
		long long r;
		for(long long l=1;l+len-1<=n;l++)
		{
			r=l+len-1;
			if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m)
			{
				return true;
			}
		}
		return false;
	};
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}