#include <bits/stdc++.h>

using namespace std;

typedef  long long ll;

int c, n, m, d, q;
ll w[1000010];
vector<pair<int, ll>> e[1000010], g[1000010];
ll dist[510][510]; bool st[1000010];

void dijkstra(int s, ll dist[]) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	for (int i = 1; i <= n; ++i) dist[i] = 1ll << 60, st[i] = false;
//	cout << idx << "\n";
	dist[s] = 0; q.push({0, s});
//	cout << "----" << s << "\n";

	while (q.size()) {
		auto t = q.top(); q.pop();
		if (st[t.second]) continue;
//		cout << t.first << ' ' << t.second << "\n";
		st[t.second] = true;
		
		for (auto v : e[t.second]) {
//			cout << v.first << ' ' << v.second << ' ' << dist[v.first] << "\n";
			if (dist[v.first] > dist[t.second] + v.second) {
				dist[v.first] = dist[t.second] + v.second;
				q.push({dist[v.first], v.first});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		for (int j = 1; j <= k; ++j) {
			int x, t; cin >> x >> t;
			
			g[x].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		for (auto v : g[i]) {
			for (auto u : g[i]) {
				if (v.first != u.first) {
//					cout << v.first << '-' << u.first << "\n"; 
					e[v.first].push_back({u.first, u.second + v.second});
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		dijkstra(i, dist[i]);
	}
	
	for (int i = 1; i <= q; ++i) {
		int s, t; cin >> s >> t;
		
		ll ans = 1ll << 60;
		for (auto u : g[s]) {
			for (auto v : g[t]) {
				ans = min(ans, dist[u.first][v.first] + u.second + v.second + w[s] + w[t]);
			}
		}
		
		cout << ans << "\n";
	}

	return 0;
}
