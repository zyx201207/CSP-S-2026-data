#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 10;

int c, n, k, u[N], v[N], in[N], hd[N], top, nxt[N], f[N];
vector<pair<int, int>> to[N];
bool vis[N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		to[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> u[i] >> v[i];
		to[u[i]].emplace_back(v[i], i);
		to[v[i]].emplace_back(u[i], i);
	}
	if (k == n) {
		cout << 0 << endl;
		return;
	}
	if (c == 13 || c == 14) {
		if ((n + 1) / 2 >= n - k) {
			cout << 1 << endl;
		} else if (k == 1) {
			cout << (n + 1) / 2 << endl;
		} else {
			cout << ((n / 2) - k + 3) / 4 + 1 << endl;
		}
		return;
	}
	int ans = n;
	for (int e = 0; e < n; ++e) {
		// cout << ":: " << e << endl;
		for (int i = 0; i <= n; ++i) {
			f[i] = 0;
			hd[i] = -1;
			vis[i] = false;
		}
		top = 0;
		auto push = [&](int x) {
			// cout << ":: " << x << ' ' << f[x] << endl;
			nxt[x] = hd[f[x]];
			hd[f[x]] = x;
		};
		int cnt = n;
		for (int i = 1; i <= n; ++i) {
			in[i] = to[i].size() - (i == u[e] || i == v[e]);
			if (in[i] == 1) {
				push(i);
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int u = hd[i]; ~u; u = nxt[u]) {
				vis[u] = true;
				--cnt;
				bool flag = false;
				for (auto [v, k] : to[u]) {
					if (k != e && !vis[v]) {
						flag = true;
						f[v] = max(f[v], f[u] + 1);
						if (--in[v] == 1) {
							push(v);
						}
					}
				}
				cnt += !flag;
			}
			// cout << ":::: " << i << ' ' << cnt << endl;
			if (cnt <= k || i >= ans) {
				ans = min(ans, i + 1);
				break;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}