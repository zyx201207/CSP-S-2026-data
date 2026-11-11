#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],maxn=1;
void dfs(int id, int x, int k,int l)
{
	if (k>=l+b[id]&&id+x>maxn)
	{
		dfs(id-1,x+1,k-l-b[id],l+b[id]);
	}
	else
	{
		maxn=max(maxn,x);
	}
	return;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=0,flag=0;
	for (int i = 1; i < n; i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for (int i = 1; i < n-1; i++)
	{
		if (b[i]!=b[i+1])flag=1;
	}
	if (flag==0)
	{
		int x;
		for (int i = 1; i * (b[1]*(i+1))/2<=m; i++)
		{
			x=i;
		}
		cout<<1+x;
		return 0;
	}
	for (int i = n; i >= 1; i--)
	{
		if (i>=maxn)
		{
			dfs(i,1,m,0);
		}
	}
	cout<<maxn;
	return 0;
}
