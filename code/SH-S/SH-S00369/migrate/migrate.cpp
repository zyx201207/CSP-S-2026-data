#include <bits/stdc++.h>

using namespace std;

const int N = 2000010, M = 310, K = 100010;

long long c, t, n, d, x[N], h[M], e[K], ne[K], w[K], idx = 0, dis[M], g[M];
priority_queue<pair<long long, int> > q;

void add(int a, int b, long long c)
{
	idx ++ ;
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx;
}

void dijkstra(int st)
{
	for (int i = 1; i <= n; i ++ )
	{
		dis[i] = 1e18;
		g[i] = 0;
	}
	dis[st] = 0;
	g[st] = 1;
	q.push(make_pair(0, st));
	while (!q.empty())
	{
		pair<int, int> t = q.top();
		q.pop();
		int v = t.second;
		if (dis[v] < -t.first) continue;
		for (int i = h[v]; i; i = ne[i])
		{
			int j = e[i];
			if (dis[j] > dis[v] + w[i])
			{
				dis[j] = dis[v] + w[i];
				g[j] = g[v];
				q.push(make_pair(-dis[j], j));
			}
			else if (dis[j] == dis[v] + w[i])
			{
				g[j] += g[v];
				q.push(make_pair(-dis[j], j));
			}
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t -- )
	{
		scanf("%lld%lld", &n, &d);
		idx = 0;
		memset(h, 0, sizeof h);
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%lld", &x[i]);
		}
		bool flag = true;
		for (int i = 3; i <= n; i ++ )
		{
			if (x[i] - x[i - 1] != x[i - 1] - x[i - 2])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			if (d < x[2] - x[1])
			{
				printf("0\n");
				continue;
			}
			else if (x[2] - x[1] <= d && d < 2 * x[2] - 2 * x[1])
			{
				printf("0\n");
				continue;
			}
			else if (2 * x[2] - 2 * x[1] <= d && d < 3 * x[2] - 3 * x[1])
			{
				printf("%d\n", n - 3);
				continue;
			}
			else
			{
				printf("0\n");
				continue;
			}
		}
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 1; j <= n; j ++ )
			{
				if (abs(x[i] - x[j]) <= d && i != j)
				{
					add(i, j, 1);
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i ++ )
		{
			dijkstra(i);
			for (int j = i + 1; j <= n; j ++ )
			{
				//printf("%d ", g[j]);
				if (g[j] == 2) ans ++ ;
			}
			//printf("\n");
		}
		printf("%lld\n", ans);
	}

	return 0;
}
