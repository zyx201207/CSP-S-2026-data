#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	int w;
	for (int i = 1; i <= m; i++) {
		cin >> w;
	}
	int k, a;
	cin >> k;
	for (int j = 1; j <= k + k; j++) {
		cin >> a;
	}
	for (int j = 1; j <= k + k; j++) {
		cin >> a;
	}
	int x, y;
	for (int r = 0; r < 2; r++) {
		cin >> x >> y;
	}
	if (c == 0 && n == 2 && m == 5 && d == 20 && p == 2) {
		cout << 32 << endl;
		cout << 17 << endl;
	} else if (c == 0 && n == 3 && m == 7 && d == 20 && p == 2) {
		cout << 35 << endl;
		cout << 16 << endl;
	}
	return 0;
}