#include <bits/stdc++.h>
using namespace std;
long long w[500050], a[550][400005], t[550][400005], jh[500050][10], zt[500050];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c, n, m, d, p, k, flag_1 = 0, flag_2 = 0, idx_1, idx_2, jdx_1, jdx_2;
	long long   zx = INT_MAX;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= 2 * k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= p; i++) {
		for (int j = 1; j <= 2; j++) {
			cin >> jh[i][j];
			zt[i] += w[j];
		}
		for (int r = 1; r <= n; r++) {
			for (int q = 1; q <= k; q++) {
				if (a[r][q] == jh[i][1]) {
					if (flag_2 > t[r][q]) {
						flag_1 = t[r][q];
						idx_1 = r;
						jdx_1 = q;
					}
				}
				if (a[r][q] == jh[i][2]) {
					if (flag_2 > t[r][q]) {
						flag_2 = t[r][q];
						idx_2 = r;
						jdx_2 = q;
					}
				}
			}
			if (idx_1 == idx_2) {
				zx = min(t[idx_1][jdx_1] + t[idx_1][jdx_2], zx);

			}
		}
		cout << zt[i] + zx;
	}
	return 0;
}