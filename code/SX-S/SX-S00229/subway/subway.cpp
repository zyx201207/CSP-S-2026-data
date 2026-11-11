#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int > PII;
const int M = 5e3+10, N = 510;
int c, n, m, d, r;
int w[M], k[N], a[N][M], t[N][M];

vector<PII>g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> r;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			for (int s = 1; s <= k[i]; s++) {
				if (s == j)
					continue;
				int dis = t[i][j] + t[i][s];
				g[a[i][s]].emplace_back(a[i][j], dis);
				g[a[i][j]].emplace_back(a[i][s], dis);
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		int x, y;
		cin >> x >> y;
		bool st[M] = {0};
		int dist[M];
		memset(dist, 0x3f, sizeof dist);
		priority_queue<PII, vector<PII>, greater<PII>>q;
		q.push({0, x});
		dist[x] = 0;
		while (q.empty() == 0) {
			auto t = q.top();
			q.pop();
			int a = t.first, b = t.second;
			if (st[b] == 1)
				continue;
			st[b] = 1;
			int i = 0;
			for (auto edge : g[b]) {
				int u = edge.first, v = edge.second;
				if (b == x && i == 0) {
					dist[u] = dist[b] + v;
					q.push({v, u});
					i++;
					continue;
				}
				if (dist[u] > dist[b] + v) {
					dist[u] = dist[b] + v;
					q.push({v, u});
				}

			}
		}
		cout << dist[y] + w[x] + w[y] << endl;
	}
	return 0;
}
