#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500009];
short b[505][500009];
short e[505][500009];
vector<int>g[500009];
int len;
int u,v;
void dfs(int p,int fa)
{
	if(p==v)
	{
		return;
	}
	for(auto v:g[p])
	{
		if(v!=fa)
		{
			len++;
			dfs(v,p);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>b[i][j]>>e[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>u>>v;
		dfs(u,0);
		cout<<len*e[1][1]+a[u]+a[v]<<"\n";
	}
	return 0;
}
