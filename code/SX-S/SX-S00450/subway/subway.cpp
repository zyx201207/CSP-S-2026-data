#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N];

struct node {
	int nxt, to, w;
} e[2 * N];
int head[N], idx = 1;

void add(int u, int v, int ww) {
	e[idx].w = ww;
	e[idx].to = v;
	e[idx].nxt = head[u];
	head[u] = idx++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int id = m + 1;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<int> a(k + 1);
		for (int j = 1; j <= k; j++) {
			int t;
			cin >> a[i] >> t;
			add(a[i], id, t);
			add(id, a[i], t);
			id++;
		}
		for (int u = 2; u <= k; u++) {
			add(a[u - 1], a[u], 0);
			add(a[u], a[u - 1], 0);
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		long long ans = w[x] + w[y];

		cout << "flag" << '\n';
		vector<long long> dist(m + 1, INT_MAX);
		vector<bool> vis(m + 1, false);
		priority_queue<pair<int, int>> pq;
		pq.push({0, x});
		dist[x] = 0;
		while (!pq.empty()) {
			auto tmp = pq.top();
			pq.pop();
			int u = tmp.second;
			vis[u] = true;
			for (int i = head[u]; i; i = e[i].nxt) {
				int v = e[i].to, cost = e[i].w;
				if (dist[v] > dist[u] + cost) {
					dist[v] = dist[u] + cost;
					if (!vis[v]) {
						pq.push({-dist[v], v});
					}
				}
			}
		}
		cout << ans + dist[y] << '\n';
	}
	return 0;
}
