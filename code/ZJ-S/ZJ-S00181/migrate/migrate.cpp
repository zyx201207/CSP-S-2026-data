#include <bits/stdc++.h>

using namespace std;

int c, t;
int n, d;
int x[5005];
pair<int, int> dist[5005][5005];
vector<int> edges[5005];

inline void dijkstra(int start) {
	multiset<pair<int, int>> se;
	se.insert(make_pair(start, 0));
	dist[start][start] = {0, 1};
	while (!se.empty()) {
        int u = se.rbegin()->first;
        int w = se.rbegin()->second;
        se.erase(prev(se.end(), 1));
        if (dist[start][u].first != w) {
            continue;
        }

        for (auto ff : edges[u]) {
            int v = ff;
            if (dist[start][v].first > dist[start][u].first + 1) {
                dist[start][v] = make_pair(dist[start][u].first + 1, 1);
                se.insert({v, dist[start][u].first + 1});
            } else if (dist[start][v].first == dist[start][u].first + 1) {
                dist[start][v].second++;																					 \
            }
        }
	}
}

inline void solve1() {
    memset(dist, 0x3f, sizeof dist);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (abs(x[i] - x[j]) <= d) {
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dist[i][j].second == 2) {
               ans++;
            }
        }
	}
	cout << ans << '\n';

}

inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	solve1();
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);


	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> t;
	while (t--) {
		solve();
	}
}
