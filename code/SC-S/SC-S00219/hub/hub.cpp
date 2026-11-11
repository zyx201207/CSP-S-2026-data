#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;

int n, k;
vector <int> e[maxn];

namespace subtask_1
{
	bool b[12],vis[12];
	
	void dfs(int x)
	{
		vis[x] = 1;
		for (int y : e[x])
			if (!vis[y] && b[y]) dfs(y);
	}
	
	queue <pair <int, int> > q;
	
	int get_dis(int x)
	{
		q.push({x, 0});
		while (!q.empty())
		{
			int cur = q.front().first, stp = q.front().second;
			q.pop();
			vis[cur] = 1;
			if (b[cur]) return stp;
			for (int y : e[cur])
			{
				if (vis[y]) continue;
				q.push({y, stp + 1});
			}
		}
		return 0;
	}
	
	void solve()
	{
		int ans = 1e9;
		for (int i = 1; i <= (1 << n); i ++)
		{
			if (__builtin_popcount(i) != k) continue;
			int tmp = i;
			for (int j = 1; j <= n; j ++)
			{
				if (tmp & 1) b[j] = 1;
				else b[j] = 0;
				tmp >>= 1;
			}
			int cnt = 0;
			memset(vis, 0, sizeof(vis));
			for (int j = 1; j <= n; j ++)
			{
				if (b[j] && !vis[j])
				{
					cnt ++;
					dfs(j);
				}
			}
			if (cnt == 2)
			{
				int d = 0;
				for (int j = 1; j <= n; j ++)
				{
					memset(vis, 0, sizeof(vis));
					d = max(d, get_dis(i));
				}
				ans = min(ans, d);
			}
		}
		cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T --)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) e[i].clear();
		for (int i = 1; i < n; i ++)
		{
			int u, v;
			cin >> u >> v;
			e[u].push_back(v), e[v].push_back(u);
		}
		subtask_1::solve();
	}
	return 0;
}