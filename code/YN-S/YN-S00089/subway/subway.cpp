#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long a[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, q;
	int y = 0, mu = 0;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		for (int j = 1; j <= m; j++) {
			cin >> a[j];

			for (int t = 1; t <= q; t++) {
				cin >> a[t];

				for (int i = 1; i <= n; i++) {
					if (a[i] + a[j] > a[t]) {
						continue;
					} else {
						y = a[i] + a[j];
					}

				}
			}
		}
		cout << y;
	}
}


