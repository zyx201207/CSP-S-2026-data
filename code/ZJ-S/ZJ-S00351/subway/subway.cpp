#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[100010], cnt = 0, h[500010];
bool vis[500010];
int dis[500010];
struct edge{
	int u, v, w, nxt;
} e[40000010];
void add(int u, int v, int w) {
	e[++cnt].nxt = h[u], h[u] = cnt, e[cnt].u = u, e[cnt].v = v, e[cnt].w = w;
}
void dijstra(int u, int v) {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i <= m; i++) dis[i] = 0x3f;
	dis[u] = 0;
	while (true) {
		int f = 0;
		for (int i = 1; i <= m; i++) {
			if (!vis[i] && dis[f] > dis[i]) {
				f = i;
			}
		}
		if (!f) break;
		vis[f] = true;
		for (int i = h[f]; i; i = e[i].nxt) {
			if (dis[f] + e[i].w < dis[e[i].v]) {
				dis[e[i].v] = dis[f] + e[i].w;
			}
		}
	}
	cout << dis[v] + w[u] + w[v] << '\n';
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(h, 0, sizeof(h));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a1, t1, a2, t2;
		cin >> a1 >> t1 >> a2 >> t2;
		add(a1, a2, t1 + t2);
		add(a2, a1, t1 + t2);
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		dijstra(u, v);
	}
	return 0;
}