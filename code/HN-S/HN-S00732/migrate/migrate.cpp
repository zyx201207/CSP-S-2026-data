#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;
const int N = 5005;
int x[N], cnt[N], dis[N];
bool vis[N], opt[N][N];
struct edge {
	int u, w;
};
vector <edge> g[N];
int n, d;
priority_queue <pii, vector <pii>, greater <pii> > pq;
void dij(int s) {
	for (int i = 1; i <= n; ++i) dis[i] = 1e9, cnt[i] = vis[i] = 0;
	dis[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;	
		for (auto nxt : g[u]) {
			int v = nxt.u, w = nxt.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (cnt[v]) cnt[v] = 0;
				else cnt[v] = 1;
				pq.push({dis[v], v});
			}
			else if (dis[v] == dis[u] + w) cnt[v]++;
		}
	}
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> x[i], g[i].clear();
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		for (int j = 1; j <= n; ++j) opt[i][j] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (abs(x[i] - x[j]) <= d) {
				g[i].push_back({j, abs(x[i] - x[j])});
				g[j].push_back({i, abs(x[i] - x[j])});
				opt[i][j] = opt[j][i] = 1;
			}
		}
	}
	int ans = 0;
//	cout << opt[1][5] << "\n";
	for (int i = 1; i <= n / 2; ++i) {
//		cout << i << "II\n";
		dij(i);
		for (int j = 1; j <= n; ++j) {
//			cout << dis[j] << ' ' << cnt[j] << "\n";
			if (cnt[j] == 2 && !opt[i][j]) ans++;
		}
	}
	cout << ans << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
