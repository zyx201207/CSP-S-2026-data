#include <bits/stdc++.h>
#define ll long long

using namespace std;

int _;
inline int read() {int s = 0, w = 1; char ch = getchar(); while (ch < '0' || ch > '9') {if (ch == '-') w *= -1; ch = getchar();} while (ch >= '0' && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar(); return s * w;}
inline void write(int x) {if (x < 0) x *= -1, putchar('-'); if (x > 9) write(x / 10); putchar(x % 10 + '0');}

const int N = 5e5 + 5;
const ll inf = 1e18;
int c, n, m, d, q, idx, a[N];
short ti[N];
bool vis[N];
ll dis[N * 2], ans[1005][1005];
vector<pair<int, int> > G[N];

inline void dijkstra(int s) {
	for (int i = 0; i <= idx; ++i) dis[i] = inf, vis[i] = 0;
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qu;
	qu.push({0, s});
	int v, w;
	while (!qu.empty()) {
		int u = qu.top().second; qu.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (auto it : G[u]) {
			v = it.first, w = it.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				qu.push({dis[v], v});
			}
		}
	}
} 

inline void solve() {
	c = read(), m = read(), n = read(), d = read(), q = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	int k, u, v, w, nw;
	idx = d * n;
	for (int i = 1; i <= m; ++i) {
		k = read();
		++idx;
		v = 0;
		for (int j = 1; j <= k; ++j) {
			u = read(), w = read(), nw = u + ti[u] * n;
			G[idx].push_back({nw, w}), G[nw].push_back({idx, w});
			if (v) G[v].push_back({nw, 0}), G[nw].push_back({v, 0});
			v = nw;
			++ti[u]; 
		}
		G[0].push_back({idx, 0}), G[idx].push_back({0, 0});
	}
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
		for (int j = i + 1; j <= n; ++j) {
			ans[i][j] = inf;
			for (int k = 0; k < d; ++k) {
				ans[i][j] = min(ans[i][j], dis[j + k * n] + a[i] + a[j]);
//					cout << dis[j + k * n] << ' ' << ans[i][j] << '\n';
			}
		}
	}
	while (q--) {
		u = read(), v = read();
		if (u > v) swap(u, v);
		write(ans[u][v]), putchar('\n');
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	_ = read();
	_ = 1;
	while (_--) solve();
	return 0;
}