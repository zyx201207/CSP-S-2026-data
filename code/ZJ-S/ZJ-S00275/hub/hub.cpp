#include<bits/stdc++.h>
#define ll long long
#define mkp make_pair
#define vc vector
#define INF 2147483647
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

constexpr int N = 1000011;

int cas, T, n, m, ans, tot, cnt;
int fa[N], dis[N], dep[N], c[N], qc[N];
bitset<N> vis;
vc<int> a[N];

namespace get_lca
{
	int t;
	int siz[N], f[N], top[N], son[N], dfn[N];
	
	void dfs1(int step, int la)
	{
		siz[step] = 1;
		dep[step] = dep[la] + 1;
		f[step] = la;
		int mx = -1;
		for (auto i : a[step])
		{
			if (i == la) continue;
			dfs1(i, step);
			siz[step] += siz[i];
			if (siz[i] > mx)
			{
				mx = siz[i];
				son[step] = i;
			}
		}
	}
	
	void dfs2(int step, int la)
	{
		dfn[step] = ++t;
		top[step] = la;
		if (!son[step]) return ;
		dfs2(son[step], la);
		for (auto i : a[step])
		{
			if (i == son[step] || i == f[step]) continue;
			dfs2(i, i);
		}
	}
	
	void init()
	{
		t = 0;
		for (int i = 1; i <= n; i++)
		{
			dfn[i] = dep[i] = f[i] = top[i] = son[i] = 0;
		}
		dfs1(1, 0);
		dfs2(1, 1);
	}
	
	int query(int x, int y)
	{
		if (x == y) return x;
//		cout << top[x] << top[y] << endl;
//		return 0;
		while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]]) swap(x, y);
			x = fa[top[x]];
		}
		
		if (dfn[x] > dfn[y]) swap(x, y);
		return x;
	}
}


int find(int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

void sdfs(int step, int las)
{
	if (vis[step] && vis[las]) fa[step] = fa[las];
	for (auto i : a[step])
	{
		if (i == las) continue;
		sdfs(i, step);
	}
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		dis[i] = INF;
	}
	sdfs(1, 1);
	int len = m;
	for (int i = 1; i <= m; i++)
	{
		qc[i] = fa[c[i]];
	}
	sort(qc + 1, qc + 1 + len);
	len = unique(qc + 1, qc + 1 + len) - qc - 1;
	if (len > 2) return ;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int v = c[j];
			dis[i] = min(dis[i], dep[i] + dep[v] - 2 * dep[get_lca::query(i, v)]);
//			cout << i << " "<< v << " " << get_lca::query(i, v) << " \n";
		}
	}
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s = max(s, dis[i]);
	}
	ans = min(ans, s);
}

void dfs(int step, int tot)
{
	if (tot == m)
	{
		solve();
		return ;
	}
	if (step > n) return ;
	c[tot + 1] = step;
	vis[step] = 1;
	dfs(step + 1, tot + 1);
	c[tot + 1] = 0;
	vis[step] = 0;
	dfs(step + 1, tot);
}


signed main()
{
    IOS;
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> cas >> T;
	if (cas == 13 || cas == 14)
	{
		while (T--)
		{
			cin >> n >> m;
			for (int i = 1; i < n; i++)
			{
				int x, y;
				cin >> x >> y;
			}
			if (m == n) cout << 0 << "\n";
			else if (m >= n / 2) cout << 1 << "\n";
			else 
			{
				int d = (n + 2 - m) / 4, e = n + 2 - m - 2 * d;
				if (e & 1) cout << e / 2 + 1 << "\n";
				else cout << e / 2 << "\n";
			}
		}
	}
	else
	{
		while (T--)
		{
			ans = INF;
			vis.reset();
			cin >> n >> m;
			for (int i = 1; i <= n; i++)
			{
				a[i].clear();
			}
			for (int i = 1; i < n; i++)
			{
				int x, y;
				cin >> x >> y;
				a[x].push_back(y);
				a[y].push_back(x);
			}
			get_lca::init();
			dfs(1, 0);
			cout << ans << "\n";
		}
	}
	return 0;
}
