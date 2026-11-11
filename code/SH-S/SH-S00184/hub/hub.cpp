#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 20;
int cid, n, m, p[N], ans, dep[N], f[N][20];
vector<int> gph[N];
pii check(int u)
{
	int res = p[u];
	for (int v: gph[u])
	{
		if (v == f[u][0]) continue;
		pii now = check(v);
		res += now.fi;
		if (p[u]) res -= now.se;
	}
	return {res, p[u]};
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; --i)
	{
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; --i)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
void dfs(int stp, int cnt)
{
	if (stp > n)
	{
		if (cnt != m) return ;
		if (check(1).fi > 2) return ;
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (p[i]) continue;
			int mn = 1e18;
			for (int j = 1; j <= n; ++j)
			{
				if (!p[j]) continue;
				mn = min(mn, dep[i] + dep[j] - 2 * dep[lca(i, j)]);
			}
			res = max(res, mn);
		}
		ans = min(ans, res);
		return ;
	}
	p[stp] = 1;
	dfs(stp + 1, cnt + 1);
	p[stp] = 0;
	dfs(stp + 1, cnt);
}
void build(int u)
{
	dep[u] = dep[f[u][0]] + 1;
	for (int v: gph[u])
	{
		if (v == f[u][0]) continue;
		f[v][0] = u;
		build(v);
	}
}
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) gph[i].clear();
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		cin >> u >> v;
		gph[u].push_back(v), gph[v].push_back(u);
	}
	ans = 1e18;
	build(1);
	for (int j = 1; j <= 19; ++j) for (int i = 1; i <= n; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
	dfs(1, 0);
	cout << ans << '\n';
	return ;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> cid >> T;
	while (T--) solve();
	return 0;
}
