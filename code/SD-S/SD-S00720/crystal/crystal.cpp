#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long d[500005];
long long sum[500005];
int ans;
long long add(int s,int len)
{
	long long bh;
	bh=5*d[s]-(sum[s+len-1]-sum[s-1]);
	return bh;
}
bool check(int x)
{
	long long minn=0;
	for(int i=1;i<x;i++)
	{
		minn+=d[i]*i;
	}
	long long sg=minn,bc;
	for(int i=x+1;i<n;i++)
	{
		bc=sg+add(i,x);
		if(bc<minn)
		{
			minn=bc;
		}
		sg=bc;
	}
	return minn<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
