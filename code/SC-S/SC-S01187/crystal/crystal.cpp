#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
bool check(long long mid)
{
	long long minn=1e18;
	for(int i=mid;i<=n;i++)
	{
		minn=min(a[i]*mid-(s[i]-s[i-mid]),minn);
	}
	return m>=minn;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	long long l=0,r=n,ans=0;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
} 