//hy
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int C, T;
int n, k;
vector<int>e[N];
int f[N], dep[N];
bool vis[N];
int cnt, ans;

void dfs1(int u, int dad) {
	if (vis[u] && vis[dad] == 0) {
		cnt++;
	}
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == dad)
			continue;
		dfs1(v, u);
	}
}

void dfs2(int u, int dad) {
	f[u] = dep[u] = 0;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == dad)
			continue;
		dfs2(v, u);
	}
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == dad)
			continue;
		f[u] = max(f[u], f[v]);
		if (vis[u]) {
			continue;
		}
		f[u] = max(f[u], dep[u] + dep[v] + 1);
		dep[u] = max(dep[u], dep[v] + 1);
	}
	f[u] = max(f[u], dep[u]);
}

void wrt(int x, int p) {
	if (p == 0) {
		cnt = 0;
		dfs1(1, 0);
		if (cnt == 2) {
			dfs2(1, 0);
			ans = min(ans, f[1]);
		}
		return ;
	}
	for (int i = x; i <= n - p + 1; i++) {
		vis[i] = 1;
		wrt(x + 1, p - 1);
		vis[i] = 0;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			vis[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		ans = 1e18;
		wrt(1, k);
		cout << ans << "\n";
	}
	return 0;
}
