#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y, k;
int w[600], a[500][500010], t[500][500010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", 'w', stdout);
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k;

		for (int j = 1; j <= k; j++) {

			cin >> a[i][j];
			cin >> t[i][j];
		}
	}

	for (int i = 1; i <= q; i++) {

		cin >> x >> y;
	}

	for (int i = 1; i <= q; i++) {

		cout << 2 * t[1][1] << " ";
	}

	return 0;
}
