#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 505, M = 5e5 + 5;
int n, m, d, q, w[M]; i64 dist[N][N];
vector<pair<int, int> > info[M];

int main()
{
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int testpoint; cin >> testpoint;
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i) cin >> w[i], info[i].reserve(d);
	for (int i = 1; i <= n; ++ i)
	{
		int k, x1, x2; cin >> k;
		for (int _ = 0; _ < k; ++ _)
			cin >> x1 >> x2, info[x1].emplace_back(i, x2);
	}
	
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= n; ++ i) dist[i][i] = 0;
	for (int i = 1; i <= m; ++ i)
		for (unsigned j = 0; j < info[i].size(); ++ j)
			for (unsigned k = j + 1; k < info[i].size(); ++ k)
			{
				int u = info[i][j].first, v = info[i][k].first;
				i64 w = info[i][j].second + info[i][k].second;
				if (w < dist[u][v]) dist[u][v] = dist[v][u] = w;
			}
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i) for (int j = 1; j <= n; ++ j)
			if (k != i && k != j && i != j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	for (int idq = 1; idq <= q; ++ idq)
	{
		int x1, x2; cin >> x1 >> x2;
		i64 res = 0x3f3f3f3f3f3f3f3fLL;
		for (auto it1 : info[x1]) for (auto it2 : info[x2])
		{
			int u = it1.first, v = it2.first;
			res = min(res, it1.second + dist[u][v] + it2.second);
		}
		cout << res + w[x1] + w[x2] << '\n';
	}
	return 0;
}
