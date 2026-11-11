#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 5;
const int N = 505;
int c, n, m, d, q, w[M], kk[N];
vector<int> a[N], t[N];
int x, y, ans;

void dfs(int i, int j, int ret) {
	if (a[i][j] == y) {
		ans = min(ans, ret);
		return;
	}
	for (int k = j; k <= kk[i]; k++) {
		dfs(i, k, ret);
	}
	for (int ii = 1; ii <= n; ii++) {
		for (int jj = 1; jj <= kk[ii]; jj++) {
			if (ii != i && a[ii][jj] == a[i][j]) dfs(ii, jj, ret + t[i][j] + t[ii][jj]);
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	// cout << "//////\n";
	for (int i = 1; i <= n; i++) {
		cin >> kk[i];
		a[i].push_back(-1), t[i].push_back(-1);
		for (int j = 1; j <= kk[i]; j++) {
			int u, v;
			cin >> u >> v;
			a[i].push_back(u), t[i].push_back(v);
		}
	}
	// cout << "//////\n";
	while (q--) {
		cin >> x >> y;
		ans = INT_MAX;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= kk[i]; j++) {
				// cout << "/////\n";
				if (a[i][j] == x) dfs(i, j, 0);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}