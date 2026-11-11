/* construct : OCT 31'26 */
#include	<iostream>
#include	<vector>
#define		int		long long
using namespace std;
using pii = pair<int,int>;
constexpr int maxn = 1e6+4;
constexpr int _maxn = 4e3+4;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

pii e[maxn];
int c, t, n, k;
vector<int> G[maxn];
namespace DSU
{
	int h[maxn];
	int rt[maxn];
	void build (int n)
	{
		for (int i = 1; i <= n; i++)
		{
			h[i] = 1;
			rt[i] = i;
		}
	}
	int find (int x)
	{
		if (rt[x] == x)
			return x;
		else
			return rt[x] = find (rt[x]);
	}
	void unite (int x, int y)
	{
		if ((x = find (x)) == (y = find (y))) return ;
		if (h[x] < h[y])
			rt[x] = y;
		else
		{
			rt[y] = x;
			if (h[x] == h[y])
				h[x]++;
		}
	}
}
using namespace DSU;
namespace HLD
{
	int dfc;
	int lv[maxn];
	int rt[maxn];
	int sz[maxn];
	int dfn[maxn];
	int dep[maxn];
	int son[maxn];
	int seq[maxn];
	int top[maxn];
	void dfs (int u)
	{
		sz[u] = 1;
		son[u] = 0;
		for (auto v : G[u]) if (v != rt[u])
		{
			rt[v] = u;
			dep[v] = dep[u] + 1;
			dfs (v);
			sz[u] += sz[v];
			if (!son[u] || sz[son[u]] < sz[v])
				son[u] = v;
		}
	}
	void rdfs (int u)
	{
		seq[dfn[u] = ++dfc] = u;
		if (son[u])
		{
			top[son[u]] = top[u];
			rdfs (son[u]);
		}
		for (auto v : G[u]) if (v != rt[u] && v != son[u])
		{
			top[v] = v;
			rdfs (v);
		}
		lv[u] = dfc;
	}
	inline int Lca (int u, int v)
	{
		while (top[u] != top[v])
		{
			if (dep[top[u]] > dep[top[v]])
				u = rt[top[u]];
			else
				v = rt[top[v]];
		}
		if (dep[u] < dep[v])
			return u;
		else
			return v;
	}
}
using namespace HLD;

signed main (void)
{
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	scanf ("%lld%lld", &c, &t);
	while (t--)
	{
		scanf ("%lld%lld", &n, &k);
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 1; i < n; i++)
		{
			auto &[u, v] = e[i];
			scanf ("%lld%lld", &u, &v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		dfs (1);
		top[1] = 1;
		rdfs (1);
		int ans = inf;
		for (int st = 0; st < (1 << n); st++) if (__builtin_popcountll (st) == k) [&] ()
		{
			build (n);
			for (int i = 1; i < n; i++)
			{
				auto [u, v] = e[i];
				if ((st & (1 << (u - 1))) && (st & (1 << (v - 1))))
					unite (u, v);
			}
			int rt1 = 0;
			int rt2 = 0;
			for (int i = 1; i <= n; i++) if (st & (1 << (i - 1)))
			{
				if (!rt1)
					rt1 = i;
				else if (find (i) != find (rt1))
				{
					if (rt2)
						return ;
					else
						rt2 = find (i);
				}
			}
			int mx = 0;
			for (int i = 1; i <= n; i++) if (st & (1 << (i - 1)))
			{
				int mn = inf;
				for (int j = i + 1; j <= n; j++) if (st & (1 << (j - 1)))
					mn = min (mn, dep[i] + dep[j] - dep[Lca (i, j)] * 2);
				// cout << st << " : " << i << ' ' << mn << endl;
				if (mn != inf)
					mx = max (mx, mn);
			}
			ans = min (ans, mx);
			// if (!mx)
			// 	cout << st << ' ';
		} ();
		// cout << " : ";
		printf ("%lld\n", ans);
	}
	return 0;
}
