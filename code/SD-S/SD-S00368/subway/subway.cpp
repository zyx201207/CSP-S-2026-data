# include <bits/stdc++.h>
using namespace std;
# define int long long 
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second 
const int N = 505, M = 500005; // N: xianlu M: zhandian

int c, n, m, d, q; 
int w[M];
vector <pair <int, int>> e[M];
int g[N][N], ans[N][N];
void solve ()
{
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ )
		cin >> w[i];
	for (int i = 1; i <= n; i ++ )
	{
		int k; cin >> k;
		while (k -- )
		{
			int u, w; cin >> u >> w;
			e[u].push_back ({m + i, w});
		}
	}
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= n; j ++ )
			g[i][j] = 1e18;
		g[i][i] = 0;
	}
	for (int u = 1; u <= m; u ++ )
	{
		for (int i = 0; i < (int)e[u].size (); i ++ )
		{
			for (int j = i + 1; j < (int)e[u].size (); j ++ )
			{
				int v1 = e[u][i].fi - m, w1 = e[u][i].se;
				int v2 = e[u][j].fi - m, w2 = e[u][j].se;
				g[v1][v2] = min (g[v1][v2], w1 + w2);
				g[v2][v1] = min (g[v2][v1], w1 + w2);
			}
		}
	}
	for (int k = 1; k <= n; k ++ )
	{
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= n; j ++ )
				g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
		}
	}
	while (q -- )
	{
		int st, ed; cin >> st >> ed;
		int ans = 1e18;
		for (auto it1 : e[st])
		{
			int v1 = it1.fi, w1 = it1.se;
			for (auto it2 : e[ed])
			{
				int v2 = it2.fi, w2 = it2.se;
				ans = min (ans, g[v1 - m][v2 - m] + w1 + w2);
			}
		}
		cout << ans + w[st] + w[ed] << "\n";
	}
}
signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("subway.in", "r", stdin), freopen ("subway.out", "w", stdout);
	int T; T = 1;
	while (T -- )
		solve ();
	return 0;
}
