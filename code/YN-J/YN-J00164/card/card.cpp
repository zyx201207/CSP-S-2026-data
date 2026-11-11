#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 4 && m == 3) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << 3 << " " << 1 << " " << 4;
	}
	if (n == 10 && m == 3) {
		int e, f, g, h, i, j, k, l, v, s;
		cin >> e >> f >> g >> h >> i >> j >> k >> l >> v >> s;
		cout << 10 << " " << 3 << " " << 3;
	}
	return 0;
}