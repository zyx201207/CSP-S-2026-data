#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 500, M = 500000;
struct node {
	int nxt, to, wei;
} edge[(M << 1) + 5];
int idx, head[N];
void addedge(int u, int v) {
	edge[++idx] = {head[u], v};
	head[u] = idx;
}
struct cmp {
	ll a;
	int b, c;
	bool operator< (const cmp &x) const {
		return x.a > a;
	}
};
int C, n, m, d, q;
int cnt[N][N], id[N], w[N], t[N][N], f[N][N];
ll dist[N];
bool vis[N];
void dijkstra(int u, int v) {
	priority_queue<cmp> q;
	vis[u] = true;
	q.push({0, u, -1});
	for (int i = 1; i <= n; i++) {
		dist[i] = LONG_LONG_MAX;
		vis[i] = true; 
	}
	dist[u] = 0;
	while (!q.empty()) {
		int u = q.top().b, la = q.top().c;
		q.pop();
		if (vis[u]) {
			return ;
		}
		vis[u] = true;
		for (int i = head[u], v; ~i; i = edge[i].nxt) {
			v = edge[i].to;
			if (cnt[u][v] != la) {
				if (dist[u] + t[la][v] + t[cnt[u][v]][v] < dist[v]) {
					dist[v] = dist[u] + t[la][v] + t[cnt[u][v]][v];
					q.push({dist[v], v, cnt[u][v]});
				} 
			} else {
				if (dist[u] < dist[v]) {
					dist[v] = dist[u];
					q.push({dist[v], v, cnt[u][v]});
				} 				
			}
			
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(head, -1, sizeof(head));
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1, v; j <= k; j++) {
			cin >> v >> t[i][j];
			addedge(i, v), addedge(v, i);
			cnt[v][i] = i;
			cnt[i][v] = i;
		}
	}
	
	while (q--) {
		int u, v;
		cin >> u >> v;
		dijkstra(u, v);
		cout << dist[v] + w[u] + w[v] << endl;
	}
	return 0;
}