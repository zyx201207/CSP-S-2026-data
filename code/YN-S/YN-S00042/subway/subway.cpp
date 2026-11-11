#include <bits/stdc++.h>
using namespace std;

int c, n, d;
unsigned long long m, q, dp[5001][5001], t[5001][5001], k, x, y, a[5001][5001], temp[5001], site[5001][5001],
         te, pa[5001][5001];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;

	for (int i = 0; i < 5001; i++) {

		for (int j = 0; j < 5001; j++) {

			t[i][j] = dp[i][j] = pa[i][j] = 1 << 30;
		}
	}

	for (int i = 1; i <= m; i++) {

		cin >> t[i][i];
		dp[i][i] = t[i][i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k;

		for (int j = 1; j <= k; j++) {

			cin >> a[i][j];
			cin >> temp[j];
			pa[i][a[i][j]] = temp[j];

		}

		for (int j = 1; j <= k; j++) {

			for (int p = 1; p <= k; p++) {

				te = t[a[i][j]][a[i][p]];

				if (j != p) {
					t[a[i][j]][a[i][p]] = min(t[a[i][j]][a[i][j]] + pa[i][a[i][j]] + pa[i][a[i][p]], t[a[i][j]][a[i][p]]);

					if (te != t[a[i][j]][a[i][p]]) {
						site[a[i][j]][a[i][p]] = i;
					}
				}
			}
		}
	}

	for (int p = 1; p <= m; p++) {

		for (int j = 1; j <= m; j++) {

			for (int i = 1; i < m; i++) {


				if (  site[i][p] != 0 && site[p][j] != 0) {
					dp[i][j] = min( t[i][i]  + pa[site[i][j]][i] + pa[site[i][j]][j] + t[j][j], dp[i][j]);
					dp[i][j] = min(dp[i][j], t[i][i] + pa[site[i][p]][p] + pa[site[i][p]][i] + pa[site[p][j]][j] + pa[site[p][j]][p] +
					               t[j][j]ub);
				}



			}
		}
	}


	for (int i = 0; i < q; i++) {

		cin >> x >> y;
		cout << dp[x][y];
	}
}