#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair

int read()
{
	int x = 0;
	bool f = true;
	char c = getchar();
	while (c < '0' || c > '9')
		f = (c != '-'), c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

void write(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar((x % 10) ^ 48);
}

int c, n, m, d, q;
vector<pair<int, int> > adj[5005];
int dist[5005][5005];
priority_queue<pair<int, int> > pq;

void Dij(int s)
{
	dist[s][s] = 0;
	pq.push(mp(0, s));
	while (!pq.empty())
	{
		int dis = -pq.top().first,
			u = pq.top().second;
		pq.pop();
		if (dis > dist[s][u])
			continue;
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i].first, w = adj[u][i].second;
			if (dis + w < dist[s][v])
			{
				dist[s][v] = dis + w;
				pq.push(mp(-dist[s][v], v));
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for (int i = 1, w; i <= m; ++i)
	{
		w = read();
		adj[i].pb(mp(i + m, w));
		adj[i + m].pb(mp(i, w));
	}
	for (int i = 1, k; i <= n; ++i)
	{
		k = read();
		for (int j = 1, a, w; j <= k; ++j)
		{
			a = read();
			w = read();
			adj[a + m].pb(mp(2 * m + i, w));
			adj[2 * m + i].pb(mp(a + m, w));
		}
	}
	memset(dist, 0x3f3f3f3f, sizeof dist);
	for (int i = 1; i <= m; ++i)
		Dij(i);
	while (q--)
	{
		int x, y;
		x = read(), y = read();
		write(dist[x][y]);
		putchar('\n');
	}
	return 0;
}