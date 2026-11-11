#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int c, t, n, k, tot, ans, res, fa[N], dis[N], d[N];
bool vis[N], vis2[N];
vector < int > g[N];
struct arr{int x, y;}a[N];
inline int read()
{
	int x = 1, p = 0;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') x = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		p = (p << 1) + (p << 3) + (c ^ 48);
		c = getchar();
	}
	return x * p;
}
inline void dij(int s)
{
	priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > q;
	for (register int i = 1;i <= n; ++ i) vis2[i] = 0, dis[i] = 1e18;
	q.push({0, s});
	dis[s] = 0;
	while (q.size())
	{
		pair < int, int > x = q.top(); q.pop();
		if (vis2[x.second]) continue;
		vis2[x.second] = 1;
		for (register int i = 0;i < g[x.second].size(); ++ i)
		{
			if (dis[g[x.second][i]] > dis[x.second] + 1)
			{
				dis[g[x.second][i]] = dis[x.second] + 1;
				q.push({dis[g[x.second][i]], g[x.second][i]});
			}
		}
	}
	for (register int i = 1;i <= n; ++ i) d[i] = min(d[i], dis[i]);
}
inline void solve()
{
	res = 1e18;
	n = read(), k = read();
	for (register int i = 1;i <= n; ++ i)
	{
		g[i].clear();
	}
	for (register int i = 1, x, y;i < n; ++ i)
	{
		cin >> x >> y;
		a[ ++ tot] = {x, y};
		g[x].push_back(y), g[y].push_back(x);
	}
	for (register int b = 0;b < (1 << n); ++ b)
	{
		int cnt = 0;
		for (register int j = 0;j <= 20; ++ j)
		{
			if ((b >> j) & 1) ++ cnt;
		}
		for (register int j = 0;j <= 20; ++ j)
		{
			vis[j] = 0;
		}
		if (cnt ^ k)
		{
			continue;
		}
		ans = 0;
		for (register int j = 0;j <= 20; ++ j)
		{
			if ((b >> j) & 1)
			{
				if (!vis[j + 1])
				{
					++ ans;
					queue < int > q;
					q.push(j + 1);
					while (q.size())
					{
						int x = q.front(); q.pop();
						if (!((b >> (x - 1)) & 1)) continue;
						if (vis[x]) continue;
						fa[x] = ans;
						vis[x] = 1;
						for (register int i = 0;i < g[x].size(); ++ i)
						{
							if (!vis[g[x][i]]) q.push(g[x][i]);
						}
					}
				}
			}
		}
		if (ans > 2) continue;
		for (register int j = 0;j <= 20; ++ j)
		{
			if ((b >> j) & 1) d[j + 1] = 0;
			else d[j + 1] = 1e18;
		}
		for (register int j = 0;j <= 20; ++ j)
		{
			if ((b >> j) & 1) dij(j + 1);
		}
		int mx = 0;
		for (register int j = 0;j < n; ++ j)
		{
			mx = max(mx, d[j + 1]);
		}
		res = min(res, mx);
	}
	cout << res << "\n";
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}//Oct31==Dec25?
