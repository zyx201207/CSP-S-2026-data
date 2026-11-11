#include <bits/stdc++.h>
using namespace std;
int w[500005], a[500005][500005], t[500005][500005], xr[500005], yr[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	int k;
	cin >> k;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= 2 * k; i++) {
			if (i % 2 == 1)
				cin >> a[j][(i + 1) / 2];
			else
				cin >> t[j][i / 2];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> xr[i] >> yr[i];
	}
	int f;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == xr) {
				f = a[i][j];
			}
		}
	}

	return 0;
}
