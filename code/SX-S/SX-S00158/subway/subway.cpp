#include <bits/stdc++.h>
using namespace std;
int w[500005], k[505], a[505][50005], t[505][50005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		int ans = w[x] + w[y];
		bool b1 = 0, b2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k[i]; j++) {
				if (a[i][j] == x && b1 == 0) {
					ans += t[i][j];
					b1 = 1;
				}
				if (a[i][j] == y && b2 == 0) {
					ans += t[i][j];
					b2 = 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
