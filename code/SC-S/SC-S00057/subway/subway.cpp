# include <bits/stdc++.h>
# define int long long
# define longlongmax 9223372036854775807
using namespace std;
int c, n, m, d, q;
int a[512][512], t[512][512]; 
int k[512], w[500012], e[512][512];
int f[512][512];
struct node
{
	int v, w;
};
vector <node> l[500012];
signed main ()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio (0), cin.tie (0), cout.tie (0);
	cin >> c >> n >> m >> d >> q;
	for (register int i = 1; i <= m; i ++) cin >> w[i];
	for (register int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		for (register int j = 1; j <= k[i]; j ++)
		{
			cin >> a[i][j] >> t[i][j];
			l[a[i][j]].push_back ((node){i, t[i][j]});
		}
	}
	for (register int i = 1; i <= n; i ++)
	{
		for (register int j = 1; j <= n; j ++)
		{
			f[i][j] = longlongmax;
		}
	}
	for (register int i = 1; i <= m; i ++)
	{
		for (register int j = 0; j < l[i].size (); j ++)
		{
			for (register int k = 0; k < l[i].size (); k ++)
			{
				register int u = l[i][j].v, v = l[i][k].v;
				register int w1 = l[i][j].w, w2 = l[i][k].w;
				if (u == v) continue;
				f[u][v] = f[v][u] = min (f[u][v], w1 + w2);
			}
		}
	}
//	f = e;
	for (register int i = 1; i <= n; i ++) f[i][i] = 0ll;
	for (register int k = 1; k <= n; k ++)
	{
		for (register int i = 1; i <= n; i ++)
		{
			for (register int j = 1; j <= n; j ++)
			{
				register long long a = f[i][k] + f[k][j]; 
				f[i][j] = min (f[i][j], a < 0 ? longlongmax : a);
			}
		}
	}
//	for (register int i = 1; i <= n; i ++)
//	{
//		for (register int j = i + 1; j <= n; j ++)
//		{
//			if (f[i][j] == 0x3f3f3f3f) cout << "num : " << i << ' ' << j << endl;
//			cout << "len : " << i << ' ' << j << ' ' << f[i][j] << endl;
//		}
//	}
	for (register int i = 1; i <= q; i ++)
	{
		register int fir, sec, ans = longlongmax, beg, end;
		cin >> fir >> sec;
		for (register int x = 0; x < l[fir].size (); x ++)
		{
			for (register int y = 0; y < l[sec].size (); y ++)
			{
				register int u = l[fir][x].v, v = l[sec][y].v;
				beg = l[fir][x].w, end = l[sec][y].w;
				ans = min (ans, f[u][v] + beg + end);
			}
		}
		cout << ans + w[fir] + w[sec] << '\n';
	}
	return 0;
}
/*
0 3 7 20 2
1 2 3 4 5 6 7
3 1 2 3 1 4 9
5 2 2 3 1 4 1 5 2 6 2
2 4 9 7 2

//许愿塔露拉QwQ

*/