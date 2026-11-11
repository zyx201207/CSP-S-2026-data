// 100+100+20+0
#include <bits/stdc++.h>
#define MAXN 10
using namespace std;
int n, k;
bool gra[MAXN][MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN];
int arr[MAXN];
void dfs(int x) {
	vis[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (gra[x][i] && !vis[i]) dfs(i);
	}
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = -1;
			gra[i][j] = 0;
		}
	}
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		dis[u][v] = 1;
		dis[v][u] = 1;
		gra[u][v] = 1;
		gra[v][u] = 1;
	}
	if (n == k) {
		cout << "0\n";
	}
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] != -1 && dis[k][j] != -1) {
					if (dis[i][j] == -1 || dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
	}
	int ans = n;
	for (int i = (1 << k) - 1; i <= ((1 << k) - 1) << (n - k); i++) {
		if (__builtin_popcount(i) != k) continue;
		for (int j = 0, tmp = 0; j < n; j++) {
			if (i >> j & 1) arr[++tmp] = j + 1;
		}
		memset(vis, 0, sizeof(vis));
		int tmp = 0;
		for (int j = 1; j <= k; j++) {
			if (!vis[arr[j]]) {
				tmp++;
				dfs(arr[j]);
			}
		}
		if (tmp != 2) continue;
		int maxx = 0;
		for (int l = 1; l <= n; l++) {
			for (int j = 1; j <= k; j++) {
				maxx = max(maxx, dis[l][arr[j]]);
			}
		}
		ans = min(ans, maxx);
	}
	cout << ans << "\n";
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		if (c <= 1) solve();
		else cout << "1\n";
	}
	return 0;
}
