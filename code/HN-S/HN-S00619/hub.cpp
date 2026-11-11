#include <bits/stdc++.h>
#define PREWORK
#define tests
#define filetestin
#define filetestout
using i64 = long long;
using ui64 = unsigned long long;
const int N = 1e6 + 5;
int T = 1, cid;
int n, k;
std::vector <int> e[N];
int fa[N], siz[N], son[N], top[N], dep[N];
void dfs1 (int u, int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	son[u] = 0;
	for (int v : e[u])
		if (v ^ f)
		{
			dfs1 (v, u);
			siz[u] += siz[v];
			if (! son[u] || siz[son[u]] < siz[v])
				son[u] = v;
		}
}
void dfs2 (int u, int tp)
{
	top[u] = tp;
	if (son[u])
		dfs2 (son[u], tp);
	for (int v : e[u])
		if (v != fa[u] && v != son[u])
			dfs2 (v, v);
}
int Lca (int u, int v)
{
	while (top[u] ^ top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			std::swap (u, v);
		u = fa[top[u]];
	}
	return (dep[u] < dep[v] ? u : v);
}
int dist (int u, int v)
	{return dep[u] + dep[v] - 2 * dep[Lca (u, v)];}
void prework ()
{
	std::cin >> cid;
}
struct brute_force
{
	int ans;
	bool vis[N];
	void dfs (int i, int c, int kc)
	{
		if (c > k || kc > 2)
			return;
		if (i > n)
		{
			if (c < k)
				return;
			std::vector <int> yzq;
			yzq.clear ();
			for (int i = 1; i <= n; ++ i)
				if (vis[i])
					yzq.push_back (i);
			int res = 0;
			for (int i = 1; i <= n; ++ i)
				if (! vis[i])
				{
					int lyh = 1e9;
					for (int j : yzq)
						lyh = std::min (lyh, dist (i, j));
					res = std::max (res, lyh);
				}
			ans = std::min (ans, res);
			return;
		}
		dfs (i + 1, c, kc);
		bool fl = 0;
		for (int v : e[i])
			fl |= vis[v];
		vis[i] = 1;
		dfs (i + 1, c + 1, kc + 1 - fl);
		vis[i] = 0;
	}
	void Main ()
	{
		ans = 1e9;
		dfs (1, 0, 0);
		std::cout << ans << '\n';
	}
}p1;
void solve ()
{
	std::cin >> n >> k;
	for (int i = 1, u, v; i < n; ++ i)
		std::cin >> u >> v,
		e[u].push_back (v),
		e[v].push_back (u);
	dfs1 (1, 0);
	dfs2 (1, 1);
	return p1.Main ();
}
void clear ()
{
	for (int i = 1; i <= n; ++ i)
		e[i].clear ();
}
signed main ()
{
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
#ifdef filetestin
	freopen ("hub.in", "r", stdin);
#endif
#ifdef filetestout
	freopen ("hub.out", "w", stdout);
#endif
#ifdef PREWORK
	prework ();
#endif
#ifdef tests
	std::cin >> T;
#endif
	while (T --)
		solve (),
		clear ();
	return 0;
}