#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = 1e14 + 10;
int c, n, m, d, q;
const int MAXN = 15010;
ll add[MAXN], dis[MAXN][MAXN];
vector<pli> g[MAXN];
bool vis[MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= 15000; i++) {
		for (int j = 1; j <= 15000; j++) {
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
		}

	}
	for (int i = 1; i <= m; i++)
		cin >> add[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int u = m + i, v, w;
		for (int i = 1; i <= k; i++) {
			cin >> v >> w;
			g[u].push_back({w, v});
			g[v].push_back({w, u});
		}
	}

	while (q--) {

		int s, t;
		cin >> s >> t;
		ll cost = add[s] + add[t];
		if (dis[s][t] != INF) {
			cout << cost + dis[s][t] << "\n";
		} else {
			for (int i = 1; i <= 15000; i++)
				vis[i] = 0;
			priority_queue<pli, vector<pli>, greater<pli>> pq;
			pq.push({0, s});
			while (!pq.empty()) {
				auto [d, u] = pq.top();
				pq.pop();
				if (vis[u])
					continue;
				vis[u] = 1;

				for (auto [w, v] : g[u]) {
					if (dis[s][v] > dis[s][u] + w) {
						dis[s][v] = dis[s][u] + w;

						pq.push({dis[s][v], v});
					}
				}

			}
			cout << dis[s][t] + cost << "\n";
		}
	}
	return 0;
}