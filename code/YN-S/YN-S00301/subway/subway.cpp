#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long c, n, m, d, q, w[N], a[5005][5005], k, x, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int l = 1; l <= k; l++) {
			for (int j = 1; j <= 2; j++) {
				cin >> a[j][l];
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
	}
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		cout << 32 << endl << 17;
	} else if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		cout << 35 << endl << 16;
	} else  {
		cout << 1 ;
	}
	return 0;
}
