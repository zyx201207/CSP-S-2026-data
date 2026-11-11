#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5+10, M = 5e5+10;
int dist[N];
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
bool st[N];

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int C, n, m, d, Q;
int we[N];

int dijkstra(int a, int b) {
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dist[1] = 0;
	q.push({0, 1});
	while (q.size()) {
		PII t = q.top();
		q.pop();
		int u = t.second;
		if (st[u])
			continue;
		st[u] = 1;
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] >= dist[u] + w[i]) {
				dist[j] = dist[u] + w[i];
			}
			q.push({dist[j], u});
		}
	}
	return dist[m];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> we[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a = 0, b = 0, t = 0;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			add(b, a, t + we[a]);
			b = a;
		}
	}
	for (int i = 1; i <= Q; i++) {
		memset(h, -1, sizeof(h));
		int x, y;
		cin >> x >> y;
		int ans = dijkstra(x, y);
		cout << ans << '\n';
	}
	return 0;
}
