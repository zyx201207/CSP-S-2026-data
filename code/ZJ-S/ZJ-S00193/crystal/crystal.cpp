#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,m;
bool check(int x)
{
	int sum=0LL;
	for(int i=1;i<x;i++)
	{
		sum+=a[i];
	}
	for(int i=x;i<=n;i++)
	{
		int y=a[i]*(x-1)-sum;
		if(y<=m)return true;
		sum-=a[i-x];
		sum+=a[i];
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2+1;
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