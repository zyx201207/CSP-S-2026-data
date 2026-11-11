#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[500005];
int n;
long long m;
bool check(long long x)
{
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=x)
		{
			continue;
		}
		cnt+=(a[x]-a[i]);
	}
	if(cnt<=m)
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=0,r=n,mid=(l+r)/2,ans=0;
	while(l<r)
	{
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
		mid=(l+r)/2;
	}
	cout<<ans<<endl;
	return 0;
}
