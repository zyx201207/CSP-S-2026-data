#include <bits/stdc++.h>

using namespace std;

const int N = 505, M = 5e5 + 5, D = 23;
const long long inf = 1e18;

int n, m, q;

int cost[M];
struct Edge { int v, w; } E[M][D];
int now_deg[M];
struct Query { int u, v; };
vector <Query > que;


long long dis[N][N];


signed main ()
{
	freopen ("subway.in ", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	
	int c, d; cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> cost[i];
	for (int i = 1; i <= n; i ++)
	{
		int k; cin >> k;
		for (int j = 1, u, w; j <= k; j ++)
			cin >> u >> w, E[u][++ now_deg[u]] = {i, w};
	}
	for (int i = 1, u, v; i <= q; i ++)
		cin >> u >> v, que.push_back ({u, v});
	
	//
	
	
	memset (dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	for (int k = 1; k <= m; k ++)
	{
		for (int i = 1; i <= now_deg[k]; i ++)
		{
			int u = E[k][i].v, w1 = E[k][i].w; 
			for (int j = i + 1; j <= now_deg[k]; j ++)
			{
				int v = E[k][j].v, w2 = E[k][j].w;
				dis[u][v] = dis[v][u] = min (dis[u][v], (long long)(w1 + w2));
			}
		}
	}
	
	//
	
//	for (int i = 1; i <= n; i ++)
//		for (int j = 1; j <= n; j ++)
//			cout << dis[i][j] << " \n"[j == n];
//	cout << "\n\n\n";

	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
	
//	for (int i = 1; i <= n; i ++)
//		for (int j = 1; j <= n; j ++)
//			cout << dis[i][j] << " \n"[j == n];
//	cout << "\n\n\n";
	
	
	//
	
	for (auto k : que)
	{
		int u = k.u, v = k.v;
		long long res = inf;
		for (int i = 1; i <= now_deg[u]; i ++)
			for (int j = 1; j <= now_deg[v]; j ++)
//				cout << E[u][i].v << " " << E[v][j].v << " " << dis[E[u][i].v][E[v][j].v] << "\n",
				res = min (res, E[u][i].w + E[v][j].w + dis[E[u][i].v][E[v][j].v]);
		cout << res + cost[u] + cost[v] << "\n";
	}
	
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

