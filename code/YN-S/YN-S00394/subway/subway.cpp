#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500050], k, ans, l, r, num[5000050], pd;

struct zd {
	int a;
	int t;
} a[490][500010];

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j].a >> a[i][j].t;
			num[a[i][j].a]++;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		ans += w[l];
		ans += w[r];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j].a == l || a[i][j].a == r) {
					pd++;
				}
			}
			if (pd == 2) {
				cout << ans << endl;
				break;
			}
		}
		if (pd != 2) {
			cout << ans + a[1][2].t << endl;
		}
	}

	return 0;
}