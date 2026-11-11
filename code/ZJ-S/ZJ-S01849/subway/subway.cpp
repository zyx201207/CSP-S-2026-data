#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 5e5 + 5;

int c, n, m, d, q;
ll w[M], dis[N][N];
bool st[N];
vector<pair<int, ll> > g[M];

inline void readint(int &x)
{
	x = 0;
	char c = getchar();
	while (!('0' <= c && c <= '9')) c = getchar();
	while ('0' <= c && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return ;
}

inline void readll(ll &x)
{
	x = 0;
	char c = getchar();
	while (!('0' <= c && c <= '9')) c = getchar();
	while ('0' <= c && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return ;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	readint(c); readint(n); readint(m); readint(d); readint(q); 
	for (int i = 1; i <= m; i++) readll(w[i]);
	for (int i = 1; i <= n; i++)
	{
		int k;
		readint(k);
		for (int j = 0; j < k; j++)
		{
			int a; ll t; readint(a); readll(t);
			g[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			for (int k = 0; k < g[i].size(); k++)
			{
				if (j == k) dis[g[i][j].first][g[i][k].first] = 0;
				else dis[g[i][j].first][g[i][k].first] = min(dis[g[i][j].first][g[i][k].first], g[i][j].second + g[i][k].second);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!dis[i][j]) continue;
			for (int k = 1; k <= n; k++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	while (q--)
	{
		int x, y; readint(x); readint(y);
		ll ans = -1;
		for (int i = 0; i < g[x].size(); i++)
		{
			for (int j = 0; j < g[y].size(); j++)
			{
				ll res = w[x] + w[y] + dis[g[x][i].first][g[y][j].first] + g[x][i].second + g[y][j].second;
				if (ans == -1) ans = res;
				else ans = min(ans, res);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
//O(d^2(m+q)+n^3)