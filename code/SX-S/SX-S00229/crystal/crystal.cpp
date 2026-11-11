#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int > PII;
const int M = 5e5+10, N = 510;
int c, n, m, d, r;
int w[M], k[N], a[N][M], t[N][M];
int dist[M][M];
vector<PII>g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> r;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		cout << w[i] << "\n";
	}

//	for (int i = 1; i <= n; i++) {
//		cin >> k[i];
//		for (int j = 1; j <= k[i]; j++) {
//			cin >> a[i][j] >> t[i][j];
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k[i]; j++) {
//			for (int s = 1; s <= k[i]; s++) {
//				int dis = t[i][j] + t[i][s];
//				cout << dis << "\n";
//				g[a[i][j]].emplace_back(a[i][s], dis);
//			}
//		}
//	}
//	for (int i = 1; i <= r; i++) {
//		int x, y;
//		cin >> x >> y;
//		bool st[M];
//		memset(dist[x], 0x3f, sizeof dist[x]);
//		priority_queue<PII, vector<PII>, greater<PII>>q;
//		q.push({0, x});
//		st[x] = 1;
//		while (!q.empty()) {
//			auto t = q.top();
//			q.pop();
//			int a = t.first, b = t.second;
//			if (st[b] == 1)
//				continue;
//			st[b] = 1;
//			for (auto edge : g[a]) {
//				int u = edge.first, v = edge.second;
//				if (dist[x][b] > dist[x][u] + v) {
//					dist[x][b] = dist[x][u] + v;
//					q.push({u, v});
//				}
//			}
//		}
//		cout << dist[x][y] + w[x] + w[y];
//	}
	return 0;
}
