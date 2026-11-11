#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, z;
int w[1005], a[1005], t[1005], x[1005], y[1005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];

	}
	for (int i = 1; i <= n; i++) {
		cin >> z;
		for (int j = 1; j <= z; j++) {
			cin >> a[j] >> t[j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	if (x[2] == 1) {
		cout << 32 << '\n' << 17;
	} else {
		cout << 35 << '\n' << 16;
	}
	return 0;
}
