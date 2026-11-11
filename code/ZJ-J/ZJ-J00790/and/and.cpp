#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],g[200005],f[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		g[i]=max(g[i-1],a[i]);
	}
	for(int j=2;j<=m;j++)
	{
		for(int i=j;i<=n;i++)
		{
			f[i]=max(f[i],max(f[i-1],g[i-1]&a[i]));
		}
		for(int i=1;i<=n;i++)
		{
			g[i]=f[i];
			f[i]=0;
		}
	}
	cout<<g[n];
}
