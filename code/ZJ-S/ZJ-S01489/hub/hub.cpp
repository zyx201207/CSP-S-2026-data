#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int c, t, n, k;
struct Edge {
	int to, ne;
} e[N << 1];
int h[N], idx;
void add(int u, int v) {
	e[idx] = {v, h[u]}, h[u] = idx ++;
}

int fa[N], dep[N];
bitset<N> vis;
void dfs(int u, int f) {
	vis[u] = 1, fa[u] = f, dep[u] = dep[f] + 1;
	for (int i = h[u]; ~i; i = e[i].ne) {
		int v = e[i].to;
		if (vis[v]) continue;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] != dep[v])
		u = fa[u];
	while (u != v)
		u = fa[u], v = fa[v];
	return u;
}

int dist(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

bool isvaild(int st) {
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		if (i != 1 && st >> i - 1 & 1 && st >> fa[i] - 1 & 1)
			cnt ++;
	return cnt == k - 1 || cnt == k - 2;
}

void solve1() {
	vis.reset();
	dfs(1, 0);
	int ans = 2e9;
	for (int st = 0; st < 1 << n; st ++)
		if (__builtin_popcount(st) == k && isvaild(st)) {
			int r = 0;
			for (int i = 1; i <= n; i ++)
				if (!(st >> i - 1 & 1)) {
					int d = 2e9;
					for (int j = 1; j <= n; j ++)
						if (st >> j - 1 & 1)
							d = min(d, dist(i, j));
					r = max(r, d);
				}
			ans = min(ans, r);
		}
	cout << ans << '\n';
}

void solve2() {
	int m = n - 1 >> 1, g = m + 1 - k, ans = 0;
	if (g % 4 == 0) ans = max(1, g / 4 + 1);
	else if (g % 4 == 1) ans = max(1, (g + 3) / 4);
	else ans = max(1, int(g / 4) + 2);
	cout << ans << '\n';
}

void solve() {
	memset(h, -1, sizeof h);
	idx = 0;
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	if (c <= 6) solve1();
	else if (c == 13 || c == 14) solve2();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}