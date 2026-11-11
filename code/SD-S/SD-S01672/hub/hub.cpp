#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10 + 10;
int c, t, n, k;
vector<int> g[N];
bool vis[N];
bool vis2[N];
int ans;
int dd[N];

void dfst(int u) {
	vis2[u] = 1;
	for (int v : g[u]) {
		if (vis[u]) {
			if (vis2[v]) {
				continue;
			}
			dfst(v);
		}
	}
}
void check() {
	memset(vis2, 0, sizeof vis2);
	memset(dd, 0x3f, sizeof dd);
	int res = 0;
	int cnt = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			if (!vis2[i]) {
				cnt++;
				dfst(i);
			}
			q.push(i);
			dd[i] = 0;
		}
	}
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (dd[v] > dd[u] + 1) {
				dd[v] = dd[u] + 1;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
				res = max(res, dd[i]);
			}
	if (cnt <= 2)
	ans = min(ans, res);
}
void dfs(int i, int cnt) {
	if (i > n) {
		check();
		return;
	}
	if (cnt < k) {
		vis[i] = 1;
		dfs(i + 1, cnt + 1);
		vis[i] = 0;
	}
	if (cnt + n - i + 1 > k) {
		dfs(i + 1, cnt);
	}
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(vis, 0, sizeof vis);
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
