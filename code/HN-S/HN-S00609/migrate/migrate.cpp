#include <bits/stdc++.h>
using namespace std;
const int N = 5e2;
int step[N][N], is[N][N][1000], vis[N];
struct Node {
	int i, j, k;
};
int a[N];
int T;
int dfs(int u, int root, int s);
int solve();
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> T >> T;
	while (T --) {
		cout << solve();
	}
	return 0;
}
int n, d;
int solve() {
	cin >> n >> d;
	memset(step, 0x3f, sizeof step);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (a[j] - a[i] <= d) {
				step[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				step[i][j] = min(step[i][j], step[i][k] + step[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		dfs(i, i, 0);
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (is[i][j][step[i][j]] == 2) {
				ans ++;
			}
		}
	}
	return ans;
}
int dfs(int u, int root, int s) {
	int mns = INT_MAX;
	if (s != 0) {
		is[root][u][s] ++;
		step[root][u] = s;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vis[i] = 1;
			is[i][u][s + step[u][i]];
			dfs(i, root, s + step[u][i]);
			vis[i] = 0;
		}
	}
	
}
