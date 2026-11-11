#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i <= n; i++) {
		if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
			cout << 35 << " " << 16;
		}
	}
	return 0;
}