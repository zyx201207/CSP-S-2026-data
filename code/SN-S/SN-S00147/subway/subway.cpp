#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define endl '\n'

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while('0'>ch||ch>'9')
	{
		if(ch=='-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int inf = 1e18,N = 5e2 + 10,M = 5e5 + 10;

int testid,n,m,d,q,dis[N][N],W[M];
vector<array<int,2>> pos[M],g[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	testid = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i<=m;i++)
	{
		W[i] = read();
	}
	for(int i = 1,o;i<=n;i++)
	{
		o = read();
		for(int j = 1,u,w;j<=o;j++)
		{
			u = read(),w = read();
			pos[u].push_back({i,w});
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for(int i = 1;i<=m;i++)
	{
		for(int j = 0;j<pos[i].size();j++)
		{
			int u = pos[i][j][0],w1 = pos[i][j][1];
			for(int k = j + 1;k<pos[i].size();k++)
			{
				int v = pos[i][k][0],w2 = pos[i][k][1];
				dis[u][v] = min(dis[u][v],w1+w2);
				dis[v][u] = min(dis[v][u],w1+w2);
			}
		}
	}
	for(int k = 1;k<=n;k++)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(dis[i][k]+dis[k][j]<=dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	for(int i = 1,u,v,ans;i<=q;i++)
	{
		u = read(),v = read(),ans = inf;
		for(int i1 = 0;i1<pos[u].size();i1++)
		{
			int U = pos[u][i1][0],w1 = pos[u][i1][1];
			for(int i2 = 0;i2<pos[v].size();i2++)
			{
				int V = pos[v][i2][0],w2 = pos[v][i2][1];
				ans = min(ans,dis[U][V]+w1+w2);
			}
		}
		cout<<ans+W[u]+W[v]<<endl; 
	}
	return 0;
}
//¹Ø×¢ Collapsarr ºÍ songjunhan004004 ß÷ 
