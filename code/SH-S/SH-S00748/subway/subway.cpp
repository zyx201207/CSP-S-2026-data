#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5, M = 500 + 5, INF = 1e16;

// m : 线路，n : 地铁站 
vector < pair <int, int> > bel[N]; // bel[u] : u 同时属于哪些线路，到站厅的时间  5e5 * 20 = 1e7 
int c, n, m, d, q, dz[N], ot[N], mp[M][M];
// ot[i] : i 地铁口 <-> 站厅

void init() // 输入 
{
	cin >> c >> m >> n >> d >> q;
	for (int u = 1; u <= n; u++)
		cin >> ot[u]; // 出入站时间 
	for (int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		while (k--)
		{
			int u, t;
			cin >> u >> t; // 线路 i -> 站厅 u 需要 t 
			bel[u].push_back ({i, t}); // u 属于 i，时间 t 
		}
	}
}

void build()
{
	for (int u = 1; u <= m; u++)
		for (int v = 1; v <= m; v++)
			if (u != v)	mp[u][v] = INF;
	for (int u = 1; u <= n; u++)
		for (int bel1 = 0; bel1 < bel[u].size(); bel1++)
			for (int bel2 = bel1 + 1; bel2 < bel[u].size(); bel2++) // 5e5 * 20 * 20 = 2 * 1e8
			{
				int id1 = bel[u][bel1].first, t1 = bel[u][bel1].second;
				int id2 = bel[u][bel2].first, t2 = bel[u][bel2].second;
				mp[id1][id2] = min (mp[id1][id2], t1 + t2);
				mp[id2][id1] = min (mp[id2][id1], t1 + t2); // 两个线路之间的最短时间 
			}
}

void Floyd() // 最短路 
{
	for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++) // 500 * 500 * 500 = 1.25 * 1e8
				mp[i][j] = min (mp[i][j], mp[i][k] + mp[k][j]);
}

void solve()
{
	while (q--)
	{
		int s, t, ans = INF;
		cin >> s >> t;
		for (auto l1 : bel[s])
			for (auto l2 : bel[t]) // 1e5 * 20 * 20 = 4e7 // 枚举分别所在线路 
			{
				int id1 = l1.first, id2 = l2.first;
				int zz1 = l1.second, zz2 = l2.second;
				ans = min (ans, mp[id1][id2] + zz1 + zz2 + ot[s] + ot[t]);
				// 线路之间 + 线路1 -> 站厅 + 线路2 -> 站厅 + 入站 + 出站  
			}
		cout << ans << "\n";
	}
}

signed main()
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init();
	build();
	Floyd();
	solve();
	return 0;	
}  // 80+pts
