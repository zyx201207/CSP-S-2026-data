#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read()
{
	ll f = 1, x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return f * x;
}

inline void write(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

constexpr int M = 5e5 + 2, N = 502, inf = 0x3f3f3f3f3f3f3f3f;
constexpr int P = (M + 1) * (N + 1);
ll w[M];
vector<pair<int, ll>> g[P];
int prev;
int PT;

int dijkstra(int u, int v)
{
	vector<ll> dis(PT, inf);
	vector<bool> vis(PT, false);
	dis[u] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push({0, u});
	while (!q.empty())
	{
		auto t = q.top();
		q.pop();
		if (vis[t.second])
			continue;
		vis[t.second] = true;
		for (auto p:g[t.second])
		{
			int z = p.first, w = p.second;
			if (dis[z] > t.first + w)
			{
				dis[z] = t.first + w;
				q.push({dis[z], z});
			}
		}
	}
	return dis[v] + w[u] + w[v];
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k, a, t, prev;
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i)
		w[i] = read();
	for (int i = 1; i <= n; ++i)
	{
		k = read();
		a = read(), t = read();
		prev = a;
		g[a].push_back({a * (i + 1) + m, t});
		g[a * (i + 1) + m].push_back({a, t});
		for (int j = 1; j < k; ++j)
		{
			cin >> a >> t;
			g[prev * (i + 1) + m].push_back({a * (i + 1) + m, 0});
			g[a * (i + 1) + m].push_back({prev * (i + 1) + m, 0});
			g[a * (i + 1) + m].push_back({a, t});
			g[a].push_back({a * (i + 1) + m, t});
			a = prev;
		}
	}
	PT = (n + 1) * (m + 1) + 1000;
	int z, x;
	while (q--)
	{
		z = read(), x = read();
		write(dijkstra(z, x));
		putchar('\n');
	}
	return 0;
}
