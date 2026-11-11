#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve(int c)
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
		int ANS = 1000000;
		vector<int> sta;
		vector<int> vis;
		auto dfs = [&](auto &&self, int u) -> void
		{
			for (auto v : adj[u])
			{
				if (!vis[v] && sta[v] == 1)
				{
					vis[v] = 1;
					self(self, v);
				}
			}
		};
		vector<int> dis(n + 1);
		auto dfs2 = [&](auto &&self, int u, int fa) -> void
		{
			for (auto v : adj[u])
			{
				if (v != fa)
				{
					dis[v] = dis[u] + 1;
					self(self, v, u);
				}
			}
		};
		for (int i = 0; i <= (1 << n) - 1; i++)
		{
			sta.assign(n + 1, 0);
			vis.assign(n + 1, 0);
			dis.assign(n + 1, 0);
			int tot = 0;
			for (int j = 0; j < n; j++)
			{
				if ((i >> j) & 1)
				{
					sta[j + 1] = 1;
				}
			}
			for (int u = 1; u <= n; u++)
			{
				if (sta[u]) tot++;
			}
			if (tot != k) continue;
			int cnt = 0;
			for (int u = 1; u <= n; u++)
			{
				if (sta[u] == 1 && !vis[u])
				{
					dfs(dfs, u);
					cnt++;
				}
			}
			if (cnt > 2)
			{
				continue;
			}
			int ans = 0;
			for (int u = 1; u <= n; u++)
			{
				dis[u] = 0;
				dfs2(dfs2, u, u);
				int res = 1000000;
				for (int v = 1; v <= n; v++)
				{
					if (sta[v] == 1)
					{
						res = min(res, dis[v]);
					}
				}
				ans = max(ans, res);
			}
			ANS = min(ANS, ans);
		}
		cout << ANS << endl;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		solve(c);
	}
	return 0;
}