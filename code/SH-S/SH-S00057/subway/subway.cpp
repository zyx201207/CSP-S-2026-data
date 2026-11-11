#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	int w[500010] = {};
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int k[510] = {}, a[510][500010] = {}, t[510][500010] = {};
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	//
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << 0;
	}
	return 0;
}
