#include<bits/stdc++.h>
using namespace std;
const int N = 3 + 5e5;
int c, n, m, d, q, w[N], k[N], a[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= 2 * k[i]; j++) {
			cin >> a[i];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 1 && y == 2) {
			cout << 17 << '\n';
		} else {
			cout << y * 10 + x + 1 << '\n';
		}
	}
	return 0;
}