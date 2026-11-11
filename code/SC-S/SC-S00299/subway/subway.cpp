#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 600;
const int M = 1e6 + 600;
int c, n, m, d, q;
vector<pair<int, ll> > G[M];
ll dis[M];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		int w;
		cin >> w;
		G[i].push_back({i + m, w});
		G[i + m].push_back({i, w});
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int cn;
			ll ti;
			cin >> cn >> ti;
			G[2 * m + i].push_back({cn + m, ti});
			G[cn + m].push_back({2 * m + i, ti});
		}
	}
	while (q--) {
		memset(dis, 0x3f, sizeof dis);
		int u, v;
		cin >> u >> v;
		priority_queue<pair<ll, int> > q;
		q.push({0, u});
		dis[u] = 0;
		while (!q.empty()) {
			int now = q.top().second;
			ll di = -q.top().first;
			q.pop();
			if (di > dis[now]) continue;
			for (int i = 0; i < G[now].size(); ++i) {
				int to = G[now][i].first;
				ll ti = G[now][i].second;
				if (dis[to] > dis[now] + ti) {
					dis[to] = dis[now] + ti;
					q.push({-dis[to], to});
				}
			}
		}
		cout << dis[v] << "\n";
	}
	return 0;
}