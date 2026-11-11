#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;
const int N = 505, M = 5e5 + 7;
int c, n, m, d, q;
int a[M], w[N], t[N][M], dis[1005];
bool vis[N];
struct node {
	int u, w;
};
vector <int> e[N], e2[N];
vector <node> g[M];
priority_queue <pii, vector <pii>, greater <pii> > pq; 
void dij(int s) {
	for (int i = 1; i <= m; ++i) dis[i] = 1e9, vis[i] = 0;
	dis[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
//		cout << u << "\n";
		for (auto nxt : g[u]) {
			int v = nxt.u, w = nxt.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			cin >> a[j] >> t[i][a[j]];
			e[a[j]].push_back(i);
			e2[i].push_back(a[j]);
		}
		for (int x = 1; x <= k; ++x) {
			for (int y = 1; y <= k; ++y) {
				if (x == y) continue;
				int u = a[x], v = a[y];
				g[u].push_back({v, t[i][u] + t[i][v] * 2});
				g[v].push_back({u, t[i][v] + t[i][u] * 2});	
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		dij(x);
		cout << w[x] + dis[y] + w[y] << "\n"; 
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
