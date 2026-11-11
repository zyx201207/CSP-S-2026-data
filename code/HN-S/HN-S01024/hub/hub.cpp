#include <bits/stdc++.h>

using ll = long long;
#define f first
#define s second
#define pb push_back
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 20;
int c, t, n, k, ans, fa[N], dis[N];
bool vis[N];
std::queue<int> q;
std::vector<int> g[N];

int find(int x) {
	while (fa[x] != x) x = fa[x] = fa[fa[x]];
	return x;
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	fa[y] = x;
}

void bfs(int s) {
	std::fill(dis, dis + n + 1, inf);
	std::fill(vis, vis + n + 1, false);
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto &v : g[u]) if (dis[u] + 1 < dis[v]) {
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}

void solve() {
	std::cin >> n >> k, ans = inf;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	for (int st = 1; st < (1 << n); st++) if (__builtin_popcount(st) == k) {
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) if ((st >> i - 1) & 1) for (auto &v : g[i]) if ((st >> v - 1) & 1) merge(i, v);
		int cnt = 0, mx = 0;
		for (int i = 1; i <= n; i++) if ((st >> i - 1) & 1) cnt += (fa[i] == i);
		if (cnt > 2) continue;
		for (int i = 1; i <= n; i++) {
			int mi = inf;
			bfs(i);
			for (int j = 1; j <= n; j++) if ((st >> j - 1) & 1) mi = std::min(mi, dis[j]);
			mx = std::max(mx, mi);
		}
		ans = std::min(ans, mx);
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> c >> t;
	while (t--) solve();
} 
