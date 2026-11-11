#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5, M = 505;
const ll inf = 1e18;

struct node
{
	int id, ti;
};

int c, n, m, d, q;
ll w[N], dist[M][M];
vector<node> sta[N];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
		w[i] = read();
	for (int i = 1, k; i <= n; i++)
	{
		k = read();
		for (int j = 1, aa, tt; j <= k; j++)
		{
			aa = read(), tt = read();
			sta[aa].push_back({i, tt});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = inf;
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < sta[i].size(); j++)
		{
			for (int k = j + 1; k < sta[i].size(); k++)
			{
				node u = sta[i][j], v = sta[i][k];
				dist[u.id][v.id] = dist[v.id][u.id] = min(dist[u.id][v.id], (ll)u.ti + (ll)v.ti);
			}
		}
//		for (node j : sta[i])
//		{
//			for (node k : sta[i])
//			{
//				if (j.id == k.id) continue;
//				dist[j.id][k.id] = dist[k.id][j.id] = min(dist[j.id][k.id], (ll)j.ti + (ll)k.ti);
//			}
//		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	while (q--)
	{
		int x, y;
		x = read(), y = read();
		ll ans = inf;
		for (node i : sta[x])
		{
			for (node j : sta[y])
			{
				ans = min(ans, (ll)w[x] + (ll)w[y] + dist[i.id][j.id] + (ll)i.ti + (ll)j.ti);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

/*
finished at 15:46
failed to optimize at 16:09
finished optimization at 17:05
*/