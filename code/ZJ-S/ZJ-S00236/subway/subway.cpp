#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5, M = 5e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, dd, qq, w[M], d[N + M];
struct node {
	int u, w;
	bool operator < (const node b) const {
		return w > b.w;
	}
}; vector<node> g[N + M];
priority_queue<node> q;
queue<int> que;
bool vis[N + M];
void bfs(int s, int t) {
	for (int i = 1; i <= n + m; i++) {
		d[i] = inf, vis[i] = false;
	}
	d[s] = 0, vis[s] = true; que.push(s);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (node p : g[u]) {
			if (vis[p.u]) continue;
			vis[p.u] = true, d[p.u] = d[u] + p.w;
			que.push(p.u);
		}
	}
	cout << d[t] + w[s] + w[t] << "\n";
	return ;
}
void dijkstra(int s, int t) {
	for (int i = 1; i <= n + m; i++) {
		d[i] = inf, vis[i] = false;
	}
	d[s] = 0; q.push({s, d[s]});
	while (!q.empty()) {
		int u = q.top().u; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (node p : g[u]) {
			if (d[u] + p.w < d[p.u]) {
				d[p.u] = d[u] + p.w;
				q.push({p.u, d[p.u]});
			}
		}
	}
	cout << d[t] + w[s] + w[t] << "\n";
	return ;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> dd >> qq;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j++) {
			cin >> a >> t;
			g[i + m].push_back({a, t});
			g[a].push_back({i + m, t});
		}
	}
	while (qq--) {
		int s, t; cin >> s >> t;
		if (c >= 12 && c <= 19) bfs(s, t);
		else dijkstra(s, t);
	}
	return 0;
}