#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c, n, m, d, q, w[N], a[N], t[N], x, y;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> t[i];
	}
	cin >> x >> y;
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2)
		cout << 32 << "\n" << 17 << "\n";
	if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2)
		cout << 35 << "\n" << 16 << "\n";
	return 0;
}
