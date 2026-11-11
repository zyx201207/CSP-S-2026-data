#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, cnt, w[500010], mal, minn = LLONG_MAX, xx, yy;

struct st {
	int k, r1[1010], r2[1010];
} a[510];

int main() {
	freopen("subway1.in", "r", stdin);
	freopen("subway1.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].k;
		for (int j = 1; j <= a[i].k; j++) {
			cin >> a[i].r1[j] >> a[i].r2[j];
		}
	}
	for (int l = 1; l <= q; l++) {
		cin >> xx >> yy;
		cnt = 0;
		cnt += w[xx];
		cnt += w[yy];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i].k; j++) {
				if (a[i].r1[j] == yy) {
					cnt += a[i].r2[j];
					cnt += a[i].r2[yy];
				}

			}
			if (cnt < minn) {
				minn = cnt;
			}
		}
		cout << minn << endl;
	}
	return 0;
}