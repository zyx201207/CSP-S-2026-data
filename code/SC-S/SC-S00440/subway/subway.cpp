#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -f;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
typedef long long ll;
inline ll read_ll()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -f;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write_ll(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write_ll(x / 10);
	}
	putchar(x % 10 + '0');
}
typedef unsigned long long ull;
inline ull read_ull()
{
	ull x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -f;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write_ull(ull x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write_ull(x / 10);
	}
	putchar(x % 10 + '0');
}
const int M = 1e5 + 10;
const int N = 510;
int w[M], k[N], a[N][M], t[N][M];
int c, n, m, d, q;
int gg[N][1010], ans[N][N];
void init_dfs1()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ans[i][j] = 1e9 + 10;
		}
	}
}
int gv[N];
int mn;
vector<int> g[1010];
vector<int> h[1010];
void dfs1(int ss, int tt, int u, int tr, int sum)
{
	if (u == tt)
	{
		mn = min(mn, sum);
	}
	for (auto c : g[tr])
	{
		for (auto j : h[c])
		{
			if (j != tr)
			{
				dfs1(ss, tt, c, j, sum + t[tr][c] + t[j][c]);
			}
			else
			{
				dfs1(ss, tt, u, tr, sum);
			}
		}
	}
}
int tp1, tp2;
int vis[N], sm[N][N];
int vis2[N][3];
int restw(int x)
{
	return (x == 1 ? 2 : 1);
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1; i <= m; ++i)
	{
		w[i] = read();
	}
	if (n == 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			k[i] = read();
			for (int j = 1; j <= k[i]; ++j)
			{
				a[i][j] = read();
			}
		}
		for (int i = 1; i <= q; ++i)
		{
			int x, y;
			x = read();
			y = read();
			write(w[x] + w[y] + t[x][1] + t[y][1]);
			putchar('\n');
		}
		return 0;
	}
	if (n == 2)
	{
		int mn = 1e9 + 10;
		for (int i = 1; i <= n; ++i)
		{
			k[i] = read();
			for (int j = 1; j <= k[i]; ++j)
			{
				a[i][j] = read();
				for (int r = 1; r < j; ++r)
				{
					sm[a[i][j]][a[i][r]] = 1;
				}
				t[i][j] = read();
				vis2[a[i][j]][i] = j;
//				printf(" >>> %d %d %d %d\n", vis2[a[i][j]][i], a[i][j], i, j);
				if (vis[a[i][j]])
				{
					mn = min(mn, t[1][a[i][j]] + t[2][a[i][j]]);
				}
				else
				{
					vis[a[i][j]] = 1;
				}
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (!t[i][j])
				{
					t[i][j] = 1e9;
				}
			}
		}
		for (int i = 1; i <= q; ++i)
		{
			int x, y;
			x = read();
			y = read();
			int ans = 1e9;
			int vox = vis2[x][1];
			int voy = vis2[y][1];
			int vtx = vis2[x][2];
			int vty = vis2[y][2];
			if (vox && voy && (sm[x][y] || sm[y][x]))
			{
				ans = min(ans, w[x] + w[y] + t[1][x] + t[1][y]);
			}
			if (vtx && vty && (sm[x][y] || sm[y][x]))
			{
				ans = min(ans, w[x] + w[y] + t[2][x] + t[2][y]);
			}
			if (vox && vty)
			{
				ans = min(ans, w[x] + w[y] + t[1][x] + t[2][y] + mn);
			}
			if (vtx && voy)
			{
				ans = min(ans, w[x] + w[y] + t[2][x] + t[1][y] + mn);
			}
			write(ans);
			putchar('\n');
		}
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		k[i] = read();
		if (k[i] == 2)
		{
			tp1 = read();
			tp2 = read();
			gg[tp2][i] = tp1;
			gg[tp1][i] = tp2;
		}
		for (int j = 1; j <= k[i]; ++j)
		{
			for (int r = 1; r < j; ++r)
			{
				sm[a[i][j]][a[i][r]] = i;
			}
			a[i][j] = read();
			h[a[i][j]].push_back(i);
			if (vis[a[i][j]])
			{
				g[i].push_back(a[i][j]);
				g[vis[a[i][j]]].push_back(a[i][j]);
			}
			else
			{
				vis[a[i][j]] = i;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (auto k : h[i])
			{
				init_dfs1();
				dfs1(i, j, k, i, 0);
			}
			
		}
	}
	for (int i = 1; i <= q; ++i)
	{
		int x, y;
		x = read();
		y = read();
		if (sm[x][y] || sm[y][x])
		{
			int xxx = sm[x][y] + sm[y][x];
			write(w[x] + w[y] + t[xxx][x] + t[xxx][y]);
		}
		else
		{
			write(m - n + d);
		}
		putchar('\n');
	}
	return 0;
}