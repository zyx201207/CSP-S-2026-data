#include <bits/stdc++.h>
#define int long long
#define M static_cast<int>(5e5)
using namespace std;

vector<int> w;
vector<pair<int, int>> G[M];
int dis[M];

signed main()
{
#ifndef DEBUG
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	int c, n, m, d, q;

	cin >> c >> n >> m >> d >> q;
	if (7 <= c && c <= 11)
	{
		w.resize(m + 1);
		for (int i = 1; i <= m; i++)
		{
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++)
		{
			int k, u, v, x, y;
			cin >> k >> u >> x >> v >> y;
			G[u].push_back({v, x + y});
			G[v].push_back({u, x + y});
		}

		for (int i = 1, x, y; i <= q; i++)
		{
			cin >> x >> y;
			memset(dis, 0x3f, sizeof(int) * m);
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			pq.push({0, x});
			dis[x] = 0;
			while (pq.size())
			{
				auto l = pq.top();
				pq.pop();
				int d = l.first, u = l.second;
				for (auto &v : G[u])
				{
					if (d + v.second < dis[v.first])
					{
						dis[v.first] = d + v.second;
						pq.push({dis[v.first], v.first});
					}
				}
			}
			cout << dis[y] + w[x] + w[y] << "\n";
		}
	}
	else
	{
		// w.resize(m + 1);
		// ::q.resize(q + 1);
		// for (int i = 1; i <= m; i++)
		// {
		// 	cin >> w[i];
		// }
		// for (int i = 1; i <= n; i++)
		// {
		// 	int k, a1,t1;
		// 	cin >> k >> a1>>t1;
		// 	for (int i = 1, u; i < 2*k; i++)
		// 	{
		// 		cin >> a2>>t2;
		// 		G[a1].push_back({a2,0});
		// 		G[a2].push_back({a1,0});
		// 		a1=a2,t1=t2;
		// 	}
		// }

		// for (int i = 1, x, y; i <= q; i++)
		// {
		// 	cin >> x >> y;
		// 	::q[i] = make_pair(x, y);
		// }
	}
	cout << endl;

	return 0;
}