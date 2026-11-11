#include <bits/stdc++.h>
using namespace std;
const int N=5e5+12;
const long long INF=2e18;
int n;
long long ans;
long long m,a[N],d[N];
bool cmp(long long a,long long b)
{
	return a<b;
}
bool check(int k)
{
	long long mink=INF;
	for(int i=k;i<=n;i++)
	{
		long long b=d[i-1]-d[i-k];
		b=a[i]*(k-1)-b;
		mink=min(mink,b);
	}
	if(mink<=m)
	{
		return true;
	}
	else
	{
		return false;
	}
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
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]+d[i-1];	
	}
	long long l=1;
	long long r=n;
	while(l<=r)
	{
		int mid=(l+r) >> 1;
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
