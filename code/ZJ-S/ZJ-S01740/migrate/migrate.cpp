#include <bits/stdc++.h>
#define ll long long
const int N = 2e6 + 5;
int n;
ll x[N], d, dis[N], cnt[N], vis[N];
std::vector<int> adj[N];
void solve() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (x[i] - x[j] <= d) {
				adj[i].emplace_back(j);
				adj[j].emplace_back(i);
			}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		std::queue<int> q;
		for (int j = 1; j <= n; ++j)
			dis[j] = n + 1, cnt[j] = vis[j] = 0;
		dis[i] = 0, q.emplace(i);
		cnt[i] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			if (vis[x]) continue;
			vis[x] = 1;
			for (int y : adj[x]) {
				if (dis[y] > dis[x] + 1) {
					dis[y] = dis[x] + 1, q.emplace(y), cnt[y] = cnt[x];
				} else if (dis[y] == dis[x] + 1) {
					cnt[y] = std::min(3ll, cnt[y] + cnt[x]);
				}
			} 
		}
		for (int j = i + 1; j <= n; ++j) ans += cnt[j] == 2;
	}
	std::cout << ans << "\n";
}
int get(int i, int j, int L, int R) {
	if (L > R) return 0;
	int l = i, r = j, pos = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (x[mid] >= L) r = (pos = mid) - 1;
		else l = mid + 1;
	}
	if (pos == -1) return 0;
	l = i, r = j;
	int pos1 = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (x[mid] <= R) l = (pos1 = mid) + 1;
		else r = mid - 1;
	}
	return pos1 - pos + 1;
}
void solve1() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++i)
		std::cin >> x[i];
	ll ans = 0;
	for (int j = 1, i1 = 1, i2 = 1; j <= n; ++j) {
		while (get(i1 + 1, j - 1, x[j] - d, x[i1]) > 0)
			++i1;
		while (get(i2 + 1, j - 1, x[j] - d, x[i2]) > 1)
			++i2;
		ans += std::max(0ll, (ll)i1 - (ll)i2);
	}
	std::cout << ans << "\n";
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int c, t; std::cin >> c >> t;
	while (t--) {
		if (c >= 13 && c <= 14) solve1();
		else solve();
	}
}