#include <bits/stdc++.h>
using namespace std;
int MAXN = 500086;
long long c, n, m, d, q, x, y;
int w[500086], a[510][500086], b[500086];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		for (int j = 0; j < b[i] * 2 ; j++) {
			cin >> a[i][j];
		}
	}
	while (q) {
		cin >> x >> y;
		long long  ans = 0;
		int f = 1;
		ans += w[x - 1] + w[y - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * b[i]; j++) {
				if (a[i][j] == x && j % 2 == 0) {
					ans += a[i][j + 1];
					f = 0;
					break;
				}
			}
			if (f == 0)
				break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2 * b[i]; j++) {
				if (a[i][j] == y && j % 2 == 0) {
					ans += a[i][j + 1];
					f = 0;
					break;
				}
			}
			if (f == 0)
				break;
		}
		cout << ans << endl;
		q--;
	}
	return 0;
}
