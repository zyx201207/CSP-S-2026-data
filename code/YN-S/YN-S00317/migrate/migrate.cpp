#include <bits/stdc++.h>
using namespace std;
long long a[5005];
long long dist[5005][5005], ans[5005][5005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, q;
	cin >> c >> q;
	if (c <= 10) {
		while (q--) {
			int n;
			long long d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d) {
						dist[i][j] = 1;
						ans[i][j] = 1;
					} else {
						dist[i][j] = 3e18;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					for (int k = j + 1; k <= n; k++) {
						if (dist[i][k] > dist[i][j] + dist[j][k]) {
							dist[i][k] = dist[i][j] + dist[j][k];
							ans[i][k] = 1;
						} else if (dist[i][k] == dist[i][j] + dist[j][k]) {
							ans[i][k]++;
						}
					}
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (ans[i][j] == 2) {
						cnt++;
					}
				}
			}
			cout << cnt << "\n";
		}
	} else if (c == 13 || c == 14) {
		while (q--) {
			int n;
			long long d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
			}
			int cn = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] - a[1] <= d && a[n] - a[i] <= d) {
					cn = i;
				}
			}
			long long cnt = 0;
			for (int i = 1; i < cn; i++) {
				if (i + d - 1 == cn && cn + d <= n) {
					cnt++;
				}
				if (i + d == cn && cn + d - 1 <= n) {
					cnt++;
				}
			}
			cout << cnt;
		}
	}

	return 0;
}
