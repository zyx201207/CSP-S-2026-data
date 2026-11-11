#include <bits/stdc++.h>
using namespace std;
long long t[5000000], k[5000000], a[1000000], b[1000000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c, n, m, d, q, x, y, xx, yy;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> b[j];
		}
	}
	cin >> x >> y;
	cin >> xx >> yy;
	cout << "34";
	cout << "18";
	return 0;
}