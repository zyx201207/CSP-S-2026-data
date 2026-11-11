#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int c, t, n, d, res, a[N], dis[N], cnt[N];
bool vis[N];
vector < int > g[N];
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
	for (register int i = 1;i <= n; ++ i) vis[i] = 0, cnt[i] = 0, dis[i] = 1e18;
	q.push({0, s});
	dis[s] = 0, cnt[s] = 1;
	while (q.size())
	{
		pair < int, int > x = q.top(); q.pop();
		if (vis[x.second]) continue;
		vis[x.second] = 1;
		for (register int i = 0;i < g[x.second].size(); ++ i)
		{
			if (dis[g[x.second][i]] > dis[x.second] + 1)
			{
				dis[g[x.second][i]] = dis[x.second] + 1;
				cnt[g[x.second][i]] = dis[x.second];
				q.push({dis[g[x.second][i]], g[x.second][i]});
			}
			else if (dis[g[x.second][i]] == dis[x.second] + 1)
			{
				cnt[g[x.second][i]] += dis[x.second];
			}
		}
	}
	for (register int i = s + 1;i <= n; ++ i)
	{
		if (dis[i] != 1000000000000000000 && cnt[i] == 2) ++ res;
		//cout << dis[i] << " ";
	}
	//cout << "\n";
}
inline void solve()
{
	res = 0;
	n = read(), d = read();
	for (register int i = 1;i <= n; ++ i)
	{
		a[i] = read();
		g[i].clear();
	}
	int p = a[2] - a[1];
	bool f = 0;
	for (register int i = 2;i < n; ++ i)
	{
		if (p ^ (a[i + 1] - a[i])){f = 1;break;}
	}
	for (register int i = 1;i <= n; ++ i)
	{
		for (register int j = i - 1; j >= 1; -- j)
		{
			if (a[i] - a[j] <= d) g[j].push_back(i);
		}
	}
	for (register int i = 1;i < n; ++ i)
	{
		dij(i);
	}
	cout << res << "\n";
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}//Oct31==Dec25?
