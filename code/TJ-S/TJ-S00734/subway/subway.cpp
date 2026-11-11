#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, k[505], a[505][500005], t[505][500005];
long long w[500005], dist[500505];
long long www[505][505];
bool vis_[500505];

vector<pair<int, int>> edges[500505];

long long Dij_(int x, int y) {
	memset(dist, 127, sizeof(dist));
	memset(vis_, 0, sizeof(vis_));
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
	dist[x] = 0;
	que.push({0, x});
	while (!que.empty()) {
		int u = que.top().second;
		que.pop();
		if (vis_[u])
			continue;
		vis_[u] = true;
		for (auto edge : edges[u]) {
			int v = edge.first, w = edge.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				que.push({dist[v], v});
			}
		}
	}
	return dist[y];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	if (c <= 8 || (12 <= c && c <= 19)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &k[i]);
			for (int j = 1; j <= k[i]; j++) {
				scanf("%d%d", &a[i][j], &t[i][j]);
				edges[a[i][j]].push_back({i + m, t[i][j]});
				edges[i + m].push_back({a[i][j], t[i][j]});
			}
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			long long res = Dij_(x, y);
			res += w[x] + w[y];
			printf("%lld\n", res);
		}
	} else if (9 <= c && c <= 11) {
		memset(w, 127, sizeof(w));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &k[i]);
			for (int j = 1; j <= k[i]; j++) {
				scanf("%d%d", &a[i][j], &t[i][j]);
			}
			if (k[i] == 1)
				continue;
			www[a[i][1]][a[i][2]] = min((long long)www[a[i][1]][a[i][2]], (long long)t[i][1] + t[i][2]);
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			long long res = Dij_(x, y);
			res += w[x] + w[y];
			printf("%lld\n", res);
		}
	} else {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &k[i]);
			for (int j = 1; j <= k[i]; j++) {
				scanf("%d%d", &a[i][j], &t[i][j]);
				edges[a[i][j]].push_back({i + m, t[i][j]});
				edges[i + m].push_back({a[i][j], t[i][j]});
			}
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			long long res = Dij_(x, y);
			res += w[x] + w[y];
			printf("%lld\n", res);
		}
	}
    return 0;
}
