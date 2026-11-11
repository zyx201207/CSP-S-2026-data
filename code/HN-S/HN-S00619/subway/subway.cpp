#include <bits/stdc++.h>
#define filetestin
#define filetestout
using i64 = long long;
using ui64 = unsigned long long;
const int N = 505, M = 5e5 + 5;
const i64 inf = 1e18;
bool st;
int T = 1, c, n, m, d, qq;
int w[M];
int k, a, t;

std::vector <std::pair <int, int> > e[M + N];
std::vector <std::pair <int, i64> > g[N];
void add (int u, int v, int w)
{
	e[u].push_back ({v, w});
	e[v].push_back ({u, w});
}
i64 ycy[N][N];
void addg (int u, int v, i64 w)
{
	ycy[u][v] = std::min (ycy[u][v], w);
	ycy[v][u] = std::min (ycy[v][u], w);
}
bool vis[N];
i64 dis[N][N];
void Dijkstra (int s)
{
	std::priority_queue <std::pair <i64, int> > q;
	while (q.size ())
		q.pop ();
	for (int i = 1; i <= n; ++ i)
		vis[i] = 0,
		dis[s][i] = inf;
	dis[s][s] = 0;
	q.push ({0, s});
	while (q.size ())
	{
		int u = q.top ().second;
		q.pop ();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto pr : g[u])
		{
			int v = pr.first, w = pr.second;
			if (dis[s][v] > dis[s][u] + w)
				dis[s][v] = dis[s][u] + w,
				q.push ({- dis[s][v], v});
		}
	}
}
bool ed;
void prework ()
{
}
void solve ()
{
	std::cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; ++ i)
		std::cin >> w[i];
	for (int i = 1; i <= n; ++ i)
	{
		std::cin >> k;
		while (k --)
			std::cin >> a >> t,
			add (a, i + m, t);
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			ycy[i][j] = inf;
	for (int i = 1; i <= m; ++ i)
		for (auto pr : e[i])
			for (auto pr1 : e[i])
			{
				int u = pr.first - m, v = pr1.first - m;
				if (u ^ v)
					addg (u, v, pr.second + pr1.second);
			}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (i ^ j && ycy[i][j] != inf)
				g[i].push_back ({j, ycy[i][j]});
	for (int i = 1; i <= n; ++ i)
		Dijkstra (i);
	while (qq --)
	{
		int x, y;
		std::cin >> x >> y;
		i64 res = inf;
		for (auto pr : e[x])
			for (auto pr1 : e[y])
				res = std::min (res, dis[pr.first - m][pr1.first - m] + pr.second + pr1.second);
		std::cout << res + w[x] + w[y] << '\n';
	}
	std::cerr << abs (&st - &ed) / 1024. / 1024.;
}
void clear ()
{
}
signed main ()
{
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
#ifdef filetestin
	freopen ("subway.in", "r", stdin);
#endif
#ifdef filetestout
	freopen ("subway.out", "w", stdout);
#endif
#ifdef PREWORK
	prework ();
#endif
#ifdef tests
	std::cin >> T;
#endif
	while (T --)
		solve (),
		clear ();
	return 0;
}