#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],l,r,mid,flag;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		flag=x*a[i]-sum[i]+sum[i-x];
		if(flag<=m)
		{
			return true;
		}
	}
	return false;
}
bool cmp(int x,int y)
{
	return x<y;
}
signed main()
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
		sum[i]=sum[i-1]+a[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
