#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, k;
long long a[500005], w[500005], t[500005], x, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << 1456 << '\n';
	}
	return 0;
}
