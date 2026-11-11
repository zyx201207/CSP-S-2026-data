#include<bits/stdc++.h>
using namespace std;
#define int long long

int w[500005];
int f[505][505];
struct node{
	int a,t;
};
vector <node> adj[500005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for(int i = 1;i <= n;i++)
	{
		int len;
		cin >> len;
		for(int j = 1;j <= len;j++)
		{
			int a,t;
			cin >> a >> t;
			adj[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= m;i++)
	{
		int size = adj[i].size();
		for(int j = 0;j < size;j++)
		{
			for(int k = j + 1;k < size;k++)
			{
				int u = adj[i][j].a,v = adj[i][k].a;
				f[u][v] = min(f[u][v],adj[i][j].t + adj[i][k].t);
				f[v][u] = min(f[v][u],adj[i][j].t + adj[i][k].t);
			}
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		int ans = w[l] + w[r];
		int mi = 1e18;
		for(int i = 0;i < adj[l].size();i++)
		{
			for(int j = 0;j < adj[r].size();j++)
			{
				if(adj[l][i].a == adj[r][j].a)
				{
					mi = min(mi,adj[l][i].t + adj[r][j].t);
				}
				mi = min(mi,f[adj[l][i].a][adj[r][j].a] + adj[l][i].t + adj[r][j].t);
			}
		}
		cout << ans + mi << '\n';
	}
	return 0;
}