#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int> > > a(200505);
int dist[200505];
bool b[200505];

void dijk(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > h;
	dist[s] = 0;
	h.push({0, s});
	while (!h.empty()) {
		int u = h.top().second;
		h.pop();
		if (b[u])
			continue;
		b[u] = 1;
		for (int i = 0; i < (int)a[u].size(); i++) {
			int v = a[u][i].first, w = a[u][i].second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				h.push({dist[v], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, i, j;
	cin >> c >> n >> m >> d >> q;
	for (i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		a[i].push_back({m + i, x});
		a[m + i].push_back({i, x});
	}
	for (i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (j = 1; j <= k; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[m + x].push_back({2 * m + i, y});
			a[2 * m + i].push_back({m + x, y});
		}
	}
	for (i = 1; i <= q; i++) {
		int s, t;
		cin >> s >> t;
		for (j = 1; j <= 2 * m + n; j++) {
			dist[j] = 0x3f3f3f3f;
			b[j] = 0;
		}
		dijk(s);
		printf("%d\n", dist[t]);
	}
	return 0;
}
