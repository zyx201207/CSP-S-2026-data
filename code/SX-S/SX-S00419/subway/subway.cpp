#include <bits/stdc++.h>
using namespace std;

const int N = 500005, M = 505, All = 510000;
int w[N], k[M], a[N][25], b[N][25], cnt[N], vis[All];
long long dis[M][M], dist[All];
int C, n, m, d, T;

struct Edge {
	int u;
	long long w;
	bool operator < (const Edge &x) const {
		return w > x.w;
	}
};

vector<Edge> g[All];
priority_queue<Edge> q;
queue<Edge> p;

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	int rea = 0;
	dist[s] = 0;
	q.push({ s, 0 });
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		if (u > n && u >= s) {
			rea++, dis[s - n][u - n] = dis[u - n][s - n] = dist[u];
			if (rea == n + m - s + 1)
				return;
		}
		for (auto t : g[u])
			if (dist[t.u] > dist[u] + t.w) {
				dist[t.u] = dist[u] + t.w;
				q.push({ t.u, dist[t.u] });
			}
	}
}

void bfs(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	int rea = 0;
	dist[s] = 0;
	p.push({ s, 0 });
	while (!p.empty()) {
		int u = p.front().u;
		p.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		if (u > n && u >= s) {
			rea++, dis[s - n][u - n] = dis[u - n][s - n] = dist[u];
			if (rea == n + m - s + 1)
				return;
		}
		for (auto t : g[u])
			if (dist[t.u] > dist[u] + t.w) {
				dist[t.u] = dist[u] + t.w;
				p.push({ t.u, dist[t.u] });
			}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &m, &n, &d, &T);
	for (int i = 1; i <= n; i++)
		scanf("%d", w + i);
	for (int i = 1; i <= m; i++) {
		scanf("%d", k + i);
		for (int j = 1; j <= k[i]; j++) {
			int x, val;
			scanf("%d%d", &x, &val);
			cnt[x]++;
			b[x][cnt[x]] = i;
			a[x][cnt[x]] = val;
			g[x].push_back({ n + i, val });
			g[n + i].push_back({ x, val });
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= cnt[i]; j++)
			for (int t = 1; t <= cnt[i]; t++)
				dis[b[i][j]][b[i][t]] = min(dis[b[i][j]][b[i][t]], 0ll + a[i][j] + a[i][t]);
	for (int t = 1; t <= m; t++)
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
//	for (int i = 1; i <= m; i++)
//		dijkstra(n + i);
	while (T--) {
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = 9000000000000000000ll;
		for (int i = 1; i <= cnt[x]; i++)
			for (int j = 1; j <= cnt[y]; j++)
				ans = min(ans, 0ll + w[x] + w[y] + a[x][i] + a[y][j] + dis[b[x][i]][b[y][j]]);
		printf("%lld\n", ans);
	}
	return 0;
}
// Âå¹È¹Ø×¢ Sparse_Table uid = 1046508 Ð»Ð»ß÷