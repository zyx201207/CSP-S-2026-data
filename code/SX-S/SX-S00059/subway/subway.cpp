#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[5005], a[505][500005], t[505][500005], mp[505][505], ck[505][505];

int main() {
	freopen("aubway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			for (int s = 1; s <= j; s++) {
				mp[a[i][j]][a[i][s]] = 1;
				mp[a[i][s]][a[i][j]] = 1;
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (mp[x][y]) {
			cout << w[x] + w[y] << "\n";
			continue;
		}
	}
	return 0;
}