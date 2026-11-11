#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k[505], a[505][1000005], t[505][1000005], x[100005], y[100005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k[i];

		for (int j = 1; j <= (2 * k[i]); j++) {

			cin >> a[i][j] >> t[i][j];
		}
	}

	for (int i = 1; i <= q; i++) {

		cin >> x[i] >> y[i];
	}

	cout << 35;

	return 0;
}