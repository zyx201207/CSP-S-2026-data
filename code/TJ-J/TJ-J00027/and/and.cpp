#include<bits/stdc++.h>
#define int long long
using namespace std; 
int a[200000000];
int n,m,maxn=-20;
void dfs(int d,int u,int sum)
{
	if (n-u+d<m)
	{
		return;
	}
	if (d==m)
	{
		for (int i=u;i<=n;i++)
		{
			maxn=max(maxn,sum&a[i]);
		}
		return;
	}
	for (int i=u;i<=n;i++)
	{
		if (n-i+d<m)
		{
			return;
		}
		dfs(d+1,i+1,sum&a[i]);
	}
}
signed main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (n-i+1<m)
		{
			break;
		}
		dfs(2,i+1,a[i]);
	}
	cout<<maxn;
	return 0;
}
