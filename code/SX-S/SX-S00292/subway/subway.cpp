#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int l[2000];
int a[2000][2000];
int t[2000][2000];
int b[2000];
int mp[1000];
int x, y;
int ans = INT_MAX;

void dfs(int dtz, int bh, int sum, int zl) {
	if (dtz == y) {
		ans = min(ans, sum + t[zl][bh]);
		return ;
	}
	if (mp[bh] == 1) {
		return ;
	}
	if (bh > b[zl]) {
		return ;
	}

	for (int i = 1; i <= n; i++) {
		if (i == zl)
			continue;
		for (int j = 1; j <= b[i]; j++) {
			if (a[i][j] == a[zl][bh]) {
				if (mp[a[i][j + 1]] == 0) {
					//cout << t[bh][zl + 1] << " " << t[i][j];
					dfs(a[i][j + 1], j + 1, sum + t[zl][bh] + t[i][j], i);
					mp[bh] = 0;
				}
			}
		}
	}
	//cout << endl << endl;
	if (bh < b[zl])
		dfs(a[zl][bh + 1], bh + 1, sum, zl);
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> l[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		for (int j = 1; j <= b[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][j];
		}
	}

	while (q--) {
		cin >> x >> y;
		ans = INT_MAX;
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= n; i++) {
			if (a[i][1] == x) {
				dfs(a[i][2], 2, l[x] + t[i][1], i);
			}
		}
		cout << ans + l[y] << endl;
	}

	return 0;
}

