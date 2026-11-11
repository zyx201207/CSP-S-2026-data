#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 7;
int n, d;
int c;
int ans;
int a[N];
int tot;
int cnt = INT_MAX;
bool vis[N];
void dfs(int u, int v, int f, int sum) {
	if (u == v) {
		cnt = min(cnt, sum);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (i == f) continue;
		if (vis[i] == 1) continue;
		if (abs(a[i] - a[u]) > d) continue;
		vis[i] = 1;
		dfs(i, v, u, sum + 1);
		vis[i] = 0;
	}
}
void dfs1(int u, int v, int f, int sum, int dis) {
	if (sum > dis) return ;
	if (u == v && sum == dis) {
		tot++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (i == f) continue;
		if (vis[i] == 1) continue;
		if (abs(a[i] - a[u]) > d) continue;
		vis[i] = 1;
		dfs1(i, v, u, sum + 1, dis);
		vis[i] = 0;
	}
}
void solve() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			cnt = INT_MAX;
			memset(vis, 0, sizeof(vis));
			dfs(i, j, 0, 0);
			tot = 0;
			memset(vis, 0, sizeof(vis));
			dfs1(i, j, 0, 0, cnt);
			if (tot == 2) ans++;
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
	cin >> c;
	cin >> T;
	while (T--) solve();
	return 0;
}

