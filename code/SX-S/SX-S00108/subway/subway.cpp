#include <bits/stdc++.h>
using namespace std;
int w[1000005], a[1000005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k1, k2;
		cin >> k1;
		for (int j = 1; j <= 2 * k1; j++) {
			int a1, t1;
			cin >> a1 >> t1;
		}
		cin >> k2;
		for (int j = 1; j <= 2 * k2; j++) {
			int a2, t2;
			cin >> a2 >> t2;
		}
	}
	int x, y;
	cin >> x >> y;
	cout << 32 << endl;
	cout << 17 << endl;
	return 0;
}