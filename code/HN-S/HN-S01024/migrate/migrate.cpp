#include <bits/stdc++.h>

using ll = long long;
#define f first
#define s second
#define pb push_back
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 2e6 + 10;
int c, t, n, ans, dis[N];
ll d, a[N], cnt[N];
bool vis[N];
std::queue<int> q;
std::vector<int> g[N];

void bfs(int s) {
	std::fill(dis, dis + n + 1, inf);
	std::fill(cnt, cnt + n + 1, 0);
	std::fill(vis, vis + n + 1, false);
	dis[s] = 0, cnt[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto &v : g[u]) {
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			} else if (dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
		}
	}
}

void solve() {
	std::cin >> n >> d, ans = 0;
	for (int i = 1; i <= n; i++) std::cin >> a[i], g[i].clear();
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (a[j] - a[i] <= d) g[i].pb(j), g[j].pb(i);
	for (int i = 1; i <= n; i++) {
		bfs(i);
		for (int j = i + 1; j <= n; j++) if (cnt[j] == 2) ans++;
	}
	std::cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> c >> t;
	while (t--) solve();
}
