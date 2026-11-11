#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],pre[500005],n,m;
int check(int x,int pos)
{
	if(a[pos]*(pos-x+1)-(pre[pos]-pre[x-1])<=m)
	{
		return 1;
	}
	return 0;
}
int solve(int pos)
{
	int l=1,r=pos,ans=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid,pos))
		{
			ans=max(ans,pos-mid+1);
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		int k=solve(i);
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}

/*
5 8
-3 -1 2 2 7
*/

