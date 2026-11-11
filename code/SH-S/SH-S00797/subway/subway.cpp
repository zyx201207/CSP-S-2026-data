#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500015],t[505][500015];
long long g[505][505],dis[505][505];
vector<int> g1[500015];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin >> x;
			cin >> t[i][x];
			g1[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[i][j]=1e10;
			if(i==j) g[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g1[i].size();j++)
		{
			for(int k=j+1;k<g1[i].size();k++)
			{
				int u=g1[i][j],v=g1[i][k];
				g[u][v]=min(g[u][v],(long long)t[u][i]+(long long)t[v][i]);
				g[v][u]=g[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		long long ans;
		cin >> x >> y;
		for(int i=0;i<g1[x].size();i++)
		{
			for(int j=0;j<g1[y].size();j++)
			{
				int u=g1[x][i],v=g1[y][j];
				if(i==0&&j==0) ans=t[u][x]+t[v][y]+dis[u][v];
				else ans=min(ans,t[u][x]+t[v][y]+dis[u][v]);
			}
		}
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
} 
