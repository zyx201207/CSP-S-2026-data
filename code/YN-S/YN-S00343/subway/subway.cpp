#include <bits/stdc++.h>
using namespace std;
int w[125251], a[501][125251], t[501][125251];

//AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!AC!!!
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if (c >= 12 && c <= 19) {

		}
	}
	return 0;
}
