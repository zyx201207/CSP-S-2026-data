#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q;
int w[550000];
int g[2200][2200];
void floyd()
{
	for(int k=1;k<=n+m;++k)
	{
		for(int i=1;i<=n+m;++i)
		{
			for(int j=1;j<=n+m;++j)
			{
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	return;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			int u=m+i;
			int v,w;
			cin>>v>>w;
			g[u][v]=w;
			g[v][u]=w;
		}
	}
	for(int i=1;i<=n+m;++i)
		g[i][i]=0;
	floyd();
//	for(int i=1;i<=n+m;++i)
//	{
//		for(int j=1;j<=n+m;++j)
//		{
//			cout<<g[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		cout<<(g[u][v]+w[u]+w[v])<<'\n';
	}
	return 0;
} 
