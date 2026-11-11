#include<bits/stdc++.h>
using namespace std;
long long Read() {
	long long x = 0, f = 1;
	char c;
	c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x*f;
}
const int N = 3e3+5;
int c, t;
int n, k, u, v;
vector<int> g[N];
int dp[N][N];
int ans[N], vis[N];
int vis2[N];
void dfs2(int x, int f) {
	vis2[x] = 1;
	for (int i = 0; i < g[x].size(); i++) {
		if (g[x][i] == f)continue;
		for (int j = 1; j <= k; j++) {
			if (ans[j] == g[x][i]) {
				dfs2(ans[j], x);
				break;
			}
		}
	}
}
int ans2 = 1e9;
void dfs(int x) {
	if (x == k) {
		for (int i = 1; i <= n; i++) {
			vis2[i] = 0;
		}
		int liant = 0;
		for (int i = 1; i <= x; i++) {
			if (vis2[ans[i]] == 0) {
				dfs2(ans[i], 0);
				liant++;
			}
		}
		if (liant > 2) {
			return;
		}
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			int mi = 1e9;
			for (int j = 1; j <= x; j++) {
				mi = min(mi, dp[i][ans[j]]);
			}
			mx = max(mx, mi);
		}
		ans2 = min(ans2, mx);
		return;
	}
	if (x > n)return;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			ans[x + 1] = i;
			dfs(x + 1);
			vis[i] = 0;
			ans[x + 1] = 0;
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans2 = 1e9;
		memset(dp, 0x3f, sizeof dp);
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			dp[i][i] = 0;
		}
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			dp[u][v] = 1;
			dp[v][u] = 1;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dp[i][j] > dp[i][k] + dp[k][j]) {
						dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
		dfs(0);
		cout << ans2 << '\n';
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
	}
	return 0;
}