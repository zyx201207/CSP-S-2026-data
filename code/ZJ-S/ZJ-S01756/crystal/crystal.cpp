#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long sum[500010];
long long n,m;
bool check(long long x,long long now)
{
	return (now-x+1)*a[now]-sum[now]+sum[x-1]<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long answer=0;
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i,ans=0;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid-1;
				ans=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		answer=max(answer,i-ans+1);
	}
	cout<<answer<<'\n';
	return 0;
}
