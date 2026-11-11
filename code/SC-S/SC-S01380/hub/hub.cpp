#include <bits/stdc++.h>
using namespace std;
bool cho[500010];
bool vis[500010];
vector<vector<int>> g;
bool check(int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += cho[i];
	return cnt == n;
}
void dfs(int u)
{
	if (vis[u]) return;
	for (int i = 0; i < g[u].size(); i++)
	{
		vis[i] = true;
		dfs(g[u][i]);
		vis[i] = false;
	}
}
struct pp
{
	int num;
	int dis;
};
int bfs(int u)
{
	int res = INT_MAX;
	queue<pp> q;
	q.push({u, 0});
	pp now = q.front();
	q.pop();
	for (int i = 0; i < g[u].size(); i++)
	{
		q.push({g[u][i], now.dis+1});
		if (cho[g[u][i]]) res = max(res, now.dis);
	}
	return res;
}
int calc()
{
	int cnt = 0;
	for (int i = 0; i < g.size(); i++)
	{
		if (!vis[i]) {
			cnt ++;
			memset(vis, false, sizeof(vis));
			dfs(i);
		}
	}
	if (cnt == 2) {
		int res = -0x3f3f3f3f;
		for (int i = 0; i < g.size(); i++)
		{
			res = min(bfs(i), res);
		}
		return res;
	} else return INT_MAX;
}
int main()
{
	freopen("hub.in","r", stdin);
	freopen("hub.out", "w", stdout) ;
	cin.tie(0);
	ios::sync_with_stdio(false);
	int c, t; cin >> c >> t;
	while (t--)
	{
		int n, k, ans = 0; cin >> n >> k;
		for (int i = 1; i <= n-1; i++)
		{
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			do {
				if (check(n)) ans = min(ans, calc());
			} while(next_permutation(cho+1, cho+n+1));
		}
	}
}