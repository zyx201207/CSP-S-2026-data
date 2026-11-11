#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],maxn=-1e9;
bool check(int x)
{
	int sum=0;
	for(int i=1;i<x;i++)
	{
		sum+=a[x];
	}
	return sum<=m;
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
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	int l=0-1,r=maxn;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid)==1)
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<r;
	return 0;
}

