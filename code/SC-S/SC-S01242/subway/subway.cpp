#include<bits/stdc++.h>
using namespace std;
int w[1000005];
int a[1005][1005], t[1005][1005];
int k[10000005];
int x[100005], y[100005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "r", stdout);
	int c, n, m, d, q, ans = 0;


	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	while (q--) {
		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= k[i]; j++) {

				if (a[i][j] == x[i]) {
					ans += w[a[i][j]];
					ans += t[i][j];

				}
				if (a[i][j] == y[i]) {
					ans += w[a[i][j]];
					ans += t[i][j];
				} else if (a[i][j] == a[i + 1][j]) {
					ans += w[a[i][j]];
					ans += t[i][j];
				}
			}

		}
		cout << ans << endl;
	}


	return 0;
}
