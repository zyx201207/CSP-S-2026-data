#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e6 + 10;
const int inf = 2e18;

int n, d, a[MAXN];
vector<int> adj[MAXN];

void solve(bool is) {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (is) {
		if (n == 1) return cout << 0 << '\n', void();
		int _ = a[2] - a[1];
		d = d / _;
		if (d == 0 || d == 1) return cout << 0 << '\n', void();
		cout << max(n - d - d + 1, 0LL) << '\n';
		return;
	}
	for (int i = 1; i <= n; i ++) adj[i].clear();
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (a[j] - a[i] > d) break;
			adj[i].push_back(j), adj[j].push_back(i);
		}
	}
	int ans = 0;
	for (int st = 1; st <= n; st ++) {
		vector<int> dis(n + 2, inf), cnt(n + 2, -1);
		vector<bool> vis(n + 2, false);
		dis[st] = 0, cnt[st] = 1;
		queue<int> q; q.push(st);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (vis[u]) continue;
			vis[u] = true;
			for (int v : adj[u]) {
				if (dis[v] > dis[u] + 1) {
					dis[v] = dis[u] + 1, cnt[v] = cnt[u];
					q.push(v);
				} else if (dis[v] == dis[u] + 1) {
					cnt[v] += cnt[u];
				}
			}
		}
		for (int ed = st + 1; ed <= n; ed ++) {
			if (cnt[ed] == 2) {
				ans ++;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int C, T; cin >> C >> T;
	while (T --) solve(C == 11 || C == 12);
}
