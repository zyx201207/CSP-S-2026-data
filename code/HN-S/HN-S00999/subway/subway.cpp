#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
vector<int> a[505],t[505];
struct node
{
	int v,w;
	bool operator<(const node &a)const
	{
		return a.w<w;
	}
};
vector<node> trans[500005];
int dis[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		a[i].resize(k[i]+5);
		t[i].resize(k[i]+5);
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
			trans[a[i][j]].push_back({i,t[i][j]});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i <= n;i++)
	{
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j < trans[i].size();j++)
		{
			for(int k = j+1;k < trans[i].size();k++)
			{
				int u = trans[i][j].v;
				int v = trans[i][k].v;
				dis[u][v] = min(dis[u][v],trans[i][j].w+trans[i][k].w);
				dis[v][u] = min(dis[v][u],trans[i][j].w+trans[i][k].w);
			}
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin >> u >> v;
		int ans = 1e18;
		for(auto it:trans[u])
		{
			for(auto jt:trans[v])
			{
				ans = min(ans,it.w+dis[it.v][jt.v]+jt.w);
			}
		}
		cout << ans+w[u]+w[v] << "\n";
	}
	return 0;
}

