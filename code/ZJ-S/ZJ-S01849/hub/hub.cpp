#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15, Bit = 5;
int n, k;
int fa[N][Bit], dept[N];
vector<int> g[N];
bool st[N];

inline void DFS(int u)
{
	for (int v : g[u])
	{
		if (v == fa[u][0]) continue;
		dept[v] = dept[u] + 1;
		fa[v][0] = u;
		DFS(v);
	}
	return ;
}

int zbs;

inline bool check(int u)
{
	for (int v : g[u])
	{
		if (v == fa[u][0]) continue;
		if (!st[u] && st[v]) zbs++;
		check(v);
	}
	return zbs <= 2;
}

inline int lca(int x, int y)
{
	if (dept[x] < dept[y]) swap(x, y);
	for (int i = Bit - 1; ~i; i--) if (dept[fa[x][i]] >= dept[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = Bit - 1; ~i; i--) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline int ct()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int res = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j]) continue;
			int LCA = lca(i, j);
			res = min((dept[i] - dept[LCA]) + (dept[j] - dept[LCA]), res);
		}
		ans = max(res, ans);
	}
	return ans;
}

inline void solve()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) while (!g[i].empty()) g[i].pop_back();
	for (int i = 1; i < n; i++)
	{
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
		fa[u][0] = 0;
		fa[v][0] = 0;
	}
	dept[0] = -1;
	g[0].push_back(1);
	g[1].push_back(0);
	DFS(0);
	for (int i = 1; i < Bit; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < (1 << n); i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			st[j + 1] = i >> j & 1;
			cnt += i >> j & 1;
		}
		if (cnt != k) continue;
		zbs = 0;
		if (check(0)) ans = min(ans, ct());
	}
	printf("%d\n", ans);
	return ;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t; scanf("%d %d", &c ,&t);
	while (t--) solve();
	return 0;
}
//I miss you.
