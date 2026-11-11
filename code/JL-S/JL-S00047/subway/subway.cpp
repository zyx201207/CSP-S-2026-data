#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], sum[5000005], stan;
bool vis[500005], edge[500005], vis1[500005];
struct Edge{
	int to, w;
};
vector<vector<Edge> > g;
vector<vector<Edge> > g1;
long long dfs(int st, int en)
{
	if(st == en)
	{
		return 0ll;
	}
	int len = g[st].size();
	long long minn = 2147483647;
	bool b = 1;
	if(len == 0)
	{
		edge[st] = 1;
	}
	for(int i = 0; i < len; i++)
	{
		if(vis[g[st][i].to] || edge[st])
			continue;
		vis[g[st][i].to] = 1;
		minn = min(minn, dfs(g[st][i].to, en) + g[st][i].w);
		vis[g[st][i].to] = 0;
		if(!edge[g[st][i].to])
		{
			b = 0;
		}
	}
	if(b)
	{
		edge[st] = 1;
	}
	return minn;
}
long long dfs1(int st, vector<Edge> en)
{
	int len1 = en.size();
	int len = g1[st].size();
	long long minn = 2147483647;
	for(int i = 0; i < len; i++)
	{
		if(vis1[g1[st][i].to])
			continue;
		for(int j = 0; j < len1; j++)
		{
			if(en[j].to == g1[st][i].to)
				return 4;
		}
		vis1[g1[st][i].to] = 1;
		minn = min(minn, dfs1(g1[st][i].to, en) + g1[st][i].w);
		vis1[g1[st][i].to] = 0;
	}
	return minn;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	g.resize(m + n + 1);
	g1.resize(n + 5);
	for(int i = 1; i <= n; i++)
	{
		int k;
		if(d <= 2)
		{
			cin >> k;
			int fr, t, we1, we2;
			cin >> fr >> we1 >> t >> we2;
			g[fr].push_back({t, we1 + we2});
			g[t].push_back({fr, we1 + we2});
		}
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int a, t;
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
			sum[a]++;
			if(12 <= c && c <= 19 && sum[a] >= 2)
			{
				stan = t;
				int len = g[a].size();
				for(int l = 0; l <= len; l++)
				{
					if(g[a][k].to > m)
					{
						g1[i].push_back({g[a][l].to - m, 1});
						g1[g[a][l].to - m].push_back({i, 1});
					}
				}
			}
		}
	}
	while(q--)
	{
		memset(edge, 0, sizeof(edge));
		int l, r;
		long long sum = 0;
		cin >> l >> r;
		sum += w[l] + w[r];
		if(12 <= c && c <= 19)
		{
			vector<Edge> st;
			int len = g[l].size();
			for(int k = 0; k <= len; k++)
			{
				if(g[l][k].to > m)
				{
					st.push_back({g[l][k].to - m, 1});
				}
			}
			g1[0] = st;
			vector<Edge> en;
			int len1 = g[r].size();
			for(int k = 0; k <= len1; k++)
			{
				if(g[r][k].to > m)
				{
					en.push_back({g[r][k].to - m, 1});
				}
			}
			sum += dfs1(0, en) * stan;
		}
		vis[l] = 1;
		sum += dfs(l, r);
		vis[l] = 0;
		cout << sum << '\n';
	}
	return 0;
}
