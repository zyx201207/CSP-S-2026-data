# include <bits/stdc++.h>
using namespace std;
# define int long long 
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second 
const int N = 2000005;

int n, d, Cas;
int x[N], pre[N], nxt[N];
int f[N], g[N], sum[N];
pair <int, int> seg[N * 2];
void solve ()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i ++ )
		cin >> x[i];
	bool flag = 0;
	for (int i = 2; i <= n; i ++ )
	{
		if (x[i] - x[i - 1] != x[2] - x[1])
		{
			flag = 1;
			break;
		}
	}
	for (int i = 1; i <= n; i ++ )
		pre[i] = 0;
	for (int i = 1, j = 1; i <= n; i ++ )
	{
		while (j < i && x[i] - x[j] > d)
			j ++ ;
		pre[i] = j;
	}
	if (!flag)
	{
		int ans = 0;
		int u = 1;
		for (int i = u; i <= n; i ++ )
			f[i] = 1e9, g[i] = sum[i] = 0;
		for (int i = 0; i <= n; i ++ )
			seg[i] = {0, 0};
		f[u] = 0, g[u] = 1;
		sum[u] = 1;
		seg[0] = {u, u};
		for (int i = u + 1; i <= n; i ++ )
		{
			f[i] = f[max (u, pre[i])] + 1;
			if (f[max (u, pre[i])] >= 1e9)
				continue;
			g[i] = sum[seg[f[max (u, pre[i])]].se] - sum[max ({u, pre[i], seg[f[max (u, pre[i])]].fi}) - 1];
			if (g[i] <= 0)
				g[i] = 1;
			if (!seg[f[i]].se)
				seg[f[i]] = {i, i};
			seg[f[i]].fi = min (seg[f[i]].fi, i);
			seg[f[i]].se = max (seg[f[i]].se, i);
			sum[i] = sum[i - 1] + g[i];
		}
		for (int i = u + 1; i <= n; i ++ )
		{
			if (g[i] == 2)
				ans += n - i + 1;
		}
		cout << ans << endl;
		return;
	}
	if (13 <= Cas && Cas <= 14)
	{
		for (int i = n, j = n; i >= 1; i -- )
		{
			while (j > i && x[j] - x[i] > d)
				j -- ;
			nxt[i] = j;
		}
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (nxt[i] - pre[i] == 0)
				c0 ++ ;
			if (nxt[i] - pre[i] == 1)
				c1 ++ ;
		}
		cout << c0 * c1 << endl;
		return;
	}
	int ans = 0;
	for (int u = 1; u <= n; u ++ )
	{
		for (int i = u; i <= n; i ++ )
			f[i] = 1e9, g[i] = sum[i] = 0;
		f[u] = 0, g[u] = 1;
		sum[u] = 1;
		for (int i = 0; i <= n; i ++ )
			seg[i] = {0, 0};
		seg[0] = {u, u};
		for (int i = u + 1; i <= n; i ++ )
		{
			f[i] = f[max (u, pre[i])] + 1;
			if (f[max (u, pre[i])] >= 1e9)
				continue;
			g[i] = sum[seg[f[max (u, pre[i])]].se] - sum[max ({u, pre[i], seg[f[max (u, pre[i])]].fi}) - 1];
			if (g[i] <= 0)
				g[i] = 1;
			if (!seg[f[i]].se)
				seg[f[i]] = {i, i};
			seg[f[i]].fi = min (seg[f[i]].fi, i);
			seg[f[i]].se = max (seg[f[i]].se, i);
			sum[i] = sum[i - 1] + g[i];
		}
		for (int i = u + 1; i <= n; i ++ )
		{
			if (g[i] == 2 && f[i] < 1e9)
				ans ++ ;
		}
	}
	cout << ans << endl;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
8 3
0 1 2 4 8 10 11 13

*/
signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("migrate.in", "r", stdin), freopen ("migrate.out", "w", stdout);
	int T; cin >> Cas >> T;
	while (T -- )
		solve ();
	return 0;
}
