#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5 + 10;
const int T = 1e6 + 10;
int c, n, m, d, q, sz, W[M], tmp[M], ti[M], dis[T];
struct Node {
	int v, w;
	friend bool operator < (const Node &A, const Node &B) {
		return A.w > B.w;
	}
};
vector <Node> g[T];
void dijkstra(int s, int t) {
	for (int i = 1; i <= sz; i++) dis[i] = 1e16;
	dis[s] = 0;
	priority_queue <Node> q;
	q.push({s, 0});
	while (!q.empty()) {
		int u = q.top().v, d = q.top().w;
		q.pop();
		if (d != dis[u]) continue;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v, w = g[u][i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v, dis[v]});
			}
		}
	}
	cout << W[s] + W[t] + dis[t] << '\n';
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> W[i];
	sz = m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> tmp[j] >> ti[j];
		}
		for (int j = 1; j <= k; j++) {
			sz++;
			if (j >= 2) {
				g[sz].push_back({sz - 1, 0});
				g[sz - 1].push_back({sz, 0});
			}
			g[sz].push_back({tmp[j], ti[j]});
			g[tmp[j]].push_back({sz, ti[j]});
		}
	}
//	cout << sz << '\n';
	while (q--) {
		int l, r;
		cin >> l >> r;
		dijkstra(l, r);
	}
	return 0;
} 
