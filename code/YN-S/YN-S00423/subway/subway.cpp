#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[1000001], k[1000001], a[1001][1001], t[1001][1001];
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + k[y] + a[x][y] + t[y][x202];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


