#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 10, M = 5e5 + 10;

struct node {
	int v, e;
	bool operator<(const node& other) const {
		return e > other.e;
	}
};

int c, n, m, d, q, w[M], dis[N + M];
vector<node> g[N + M];
bitset<N + M> vis;

void dijstra(int start) {
	priority_queue<node> q;
	vis.reset();
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0;
	q.push({start, 0});
	while (!q.empty()) {
		node t = q.top(); q.pop();
		if (vis[t.v]) continue;
		vis[t.v] = true;
		for (auto z : g[t.v]) {
			if (vis[z.v]) continue;
			if (t.e + z.e < dis[z.v]) {
				dis[z.v] = t.e + z.e;
				q.push({z.v, t.e + z.e});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[a].push_back({m + i, t});
			g[m + i].push_back({a, t});
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		dijstra(u);
		printf("%d\n", w[u] + dis[v] + w[v]);
	}
	return 0;
}
