#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505,M = 5e5+7,inf = 1e9+7;
int w[M];
int dis[1005][1005];
int c,n,m,d,q;
int a[N][N],t[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(i!=j) dis[i][j] = inf;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j = 1;j<=k;j++)
		{
			for(int l = 1;l<=k;l++)
			{
				int u = a[i][j],v = a[i][l];
				dis[u][v] = t[i][j]+t[i][l];
			}
		}
	}
	for(int k = 1;k<=m;k++)
	{
		for(int u = 1;u<=m;u++)
		{
			for(int v = 1;v<=m;v++)
			{
				dis[u][v] = min(dis[u][v],dis[u][k]+dis[k][v]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		cout<<w[u]+w[v]+dis[u][v]<<"\n";
	}
	return 0;
}
