#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int C;
namespace Brute {
	const int N = 3005;
	int n, m, d, q, cnt, b[N], k[N], dis[N][N], a[N][N], t[N][N];
	struct Node { int v, w; bool operator > (const Node cmp) const { return w > cmp.w; } };
	vector<Node> g[N];
	priority_queue<Node, vector<Node>, greater<Node> > pq;
	void dijk(int s) {
		fill(dis[s] + 1, dis[s] + cnt + 1, INF);
		dis[s][s] = 0; pq.push({ s, 0 });
		while (pq.size()) {
			int u = pq.top().v, d = pq.top().w; pq.pop();
			if (d != dis[s][u]) continue;
			for (auto t : g[u]) {
				int v = t.v, w = t.w;
				if (dis[s][v] > dis[s][u] + w) {
					dis[s][v] = dis[s][u] + w;
					pq.push({ v, dis[s][v] });
				}
			}
		}
	}
	void solve() {
		cin >> n >> m >> d >> q; cnt = m;
		for (int i = 1; i <= m; ++i) cin >> b[i];
		for (int i = 1; i <= n; ++i) {
			cin >> k[i]; ++cnt;
			for (int j = 1; j <= k[i]; ++j) {
				cin >> a[i][j] >> t[i][j];
				g[cnt].push_back({ a[i][j], t[i][j] });
				g[a[i][j]].push_back({ cnt, t[i][j] });
			}
		}
		for (int i = 1; i <= m; ++i) dijk(i);
		while (q--) {
			int u, v; cin >> u >> v; 
			cout << b[u] + dis[u][v] + b[v] << "\n";
		}
	}
}
namespace AC {
	const int N = 6e5 + 5, M = 505;
	int n, m, d, q, b[N], k[N], dis[M][M];
	vector<int> a[M], t[M], c[N];
	struct Node { int v, w; bool operator > (const Node cmp) const { return w > cmp.w; } };
	vector<Node> g[M];
	priority_queue<Node, vector<Node>, greater<Node> > pq;
	void dijk(int s) {
		fill(dis[s] + 1, dis[s] + n + 1, INF);
		dis[s][s] = 0; pq.push({ s, 0 });
		while (pq.size()) {
			int u = pq.top().v, d = pq.top().w; pq.pop();
			if (d != dis[s][u]) continue;
			for (auto t : g[u]) {
				int v = t.v, w = t.w;
				if (dis[s][v] > dis[s][u] + w) {
					dis[s][v] = dis[s][u] + w;
					pq.push({ v, dis[s][v] });
				}
			}
		}
	}
	void solve() {
		cin >> n >> m >> d >> q;
		for (int i = 1; i <= m; ++i) cin >> b[i];
		for (int i = 1; i <= n; ++i) {
			cin >> k[i];
			a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
			for (int j = 1; j <= k[i]; ++j) {
				cin >> a[i][j] >> t[i][j];
				c[a[i][j]].push_back(i);
			}
		}
		for (int i = 1; i <= n; ++i) sort(a[i].begin(), a[i].end());
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				for (int p = 0; p < k[i]; ++p) {
					int u = a[i][p];
					if (u == 0) continue;
					auto it = -1;
					for (int o = 0; o < k[j]; ++o) if (a[j][o] == u) { it = o; break; }
					if (it == -1) continue;
					g[i].push_back({ j, t[i][p] + t[j][it] });
					g[j].push_back({ i, t[i][p] + t[j][it] });
				}
			}
		}
		for (int i = 1; i <= n; ++i) dijk(i);
		while (q--) {
			int u, v; cin >> u >> v;
			int mn = INF;
			for (auto i : c[u]) {
				for (auto j : c[v]) {
					auto itu = lower_bound(a[i].begin(), a[i].begin(), u) - a[i].begin();
					auto itv = lower_bound(a[j].begin(), a[j].begin(), v) - a[j].begin();
					for (int p = 0; p < k[i]; ++p) if (a[i][p] == u) { itu = p; break; }
					for (int p = 0; p < k[j]; ++p) if (a[j][p] == v) { itv = p; break; }
					mn = min(mn, dis[i][j] + b[u] + b[v] + t[i][itu] + t[j][itv]);
				}
			}
			cout << mn << "\n";
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> C;
	if (C <= 11) Brute::solve();
	else AC::solve();
	return 0;
}