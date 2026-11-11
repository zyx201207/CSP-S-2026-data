#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m,a[500005],ans;
bool check(int x)
{
	int cnt=0,sum=0;
	for(int i=1,j=1;i<x;i++,j++)
	{
		cnt+=a[i]*j;
		sum+=a[i];
	}
	if(cnt<=m)
	{
		return true;
	}
	for(int i=x+1;i<=n;i++)
	{
		cnt-=sum;
		cnt+=a[i]*(x-1);
		sum+=a[i];
		sum-=a[i-x];
		if(cnt<=m)
		{
			return true;
		}
	}
	return false;
}

signed main()
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
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		a[i]=a[i+1]-a[i];
	}
	a[n]=0;
	int l=0,r=500000;
	while(l<=r)
	{
		int mid=(l+r+1)/2;
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
