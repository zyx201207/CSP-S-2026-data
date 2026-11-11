#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway6.in", "r", stdin);
	freopen("subway6.out", "w", stdout);
	int c, m, n, d, q, x, s = 0,
	                      f = 0;
	cin >> c >> n >> m >> d >> q;
	int w[10001];
	int k[101][101];
	int r[1001];
	int qr[1001] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int j = 0; j < n; j += 2) {
			cin >> k[i][j] >> k[i][j + 1];
			f++;
		}

	}
	for (int i = 0; i < q; i++) {
		cin >> r[i];
	}
	for (int i = 1; i <= m; i++) {
		if (r[i] == w[i]) {
			s += w[i];
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < f; j += 2) {
			if (k[i][j] == k[i][j + 2]) {
				s += k[i][j + 1];
				s += k[i][j + 3];
				break;
			}

		}
		break;
	}
	cout << s;
	return 0;
}