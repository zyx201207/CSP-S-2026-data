# include <bits/stdc++.h>
using namespace std;
//# define int long long 
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second 
const int N = 1000005;

int n, k, Cas;
vector <int> e[N];
struct DSU
{
	int fa[N];
	void init ()
	{
		for (int i = 0; i <= n; i ++ )
			fa[i] = i;
	}
	int find_fa (int u) { return u == fa[u] ? u : fa[u] = find_fa (fa[u]); }
	bool union_fa (int u, int v)
	{
		u = find_fa (u), v = find_fa (v);
		if (u == v)
			return 0;
		fa[v] = u;
		return 1;
	}
} dsu;
bool vvv[N];
int dis[N];
bool vis[N];
void bfs (vector <int> vec)
{
	for (int i = 1; i <= n; i ++ )
		vis[i] = 0, dis[i] = 1e9;
	queue <int> q;
	for (int u : vec)
	{
		q.push (u);
		dis[u] = 0;
	}
	while (!q.empty ())
	{
		int u = q.front (); q.pop ();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int v : e[u])
		{
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				if (vis[v])
					continue;
				q.push (v);
			}
		}
	}
}
bool check (int mid)
{
	for (int s = 0; s < (1 << n); s ++ )
	{
		if (__builtin_popcount (s) != k)
			continue;
		for (int i = 1; i <= n; i ++ )
			vvv[i] = 0;
		vector <int> vec;
		for (int i = 0; i < n; i ++ )
		{
			if (s >> i & 1)
			{
				vec.push_back (i + 1);
				vvv[i + 1] = 1;
			}
		}
		dsu.init ();
		for (auto u : vec)
		{
			for (int v : e[u])
			{
				if (vvv[v])
					dsu.union_fa (u, v);
			}
		}
		int cnt = 0;
		for (int i : vec)
		{
			if (i == dsu.find_fa (i))
				cnt ++ ;
		}
		if (cnt > 2)
			continue;
		bfs (vec);
		int mx = 0;
		for (int i = 1; i <= n; i ++ )
			mx = max (mx, dis[i]);
		if (mx <= mid)
			return 1;
	}
	return 0;
}
void solve ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ )
		e[i].clear ();
	for (int i = 1; i < n; i ++ )
	{
		int u, v; cin >> u >> v;
		e[u].push_back (v), e[v].push_back (u);
	}
	int l = 0, r = n, ans = n;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check (mid))
			r = mid - 1, ans = mid;
		else
			l = mid + 1;
	}
	cout << ans << endl;
}
signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("hub.in", "r", stdin), freopen ("hub.out", "w", stdout);
	int T; cin >> Cas >> T;
	while (T -- )
		solve ();
	return 0;
}
