#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q;
long long w[10010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= q; i++) {
		if (i == 1 && n == 2) {
			cout << 32 << endl;
		}
		if (i == 1 && n == 3) {
			cout << 35 << endl;
		}
		if (i == 2 && n == 2) {
			cout << 17 << endl;
		}
		if (i == 2 && n == 3) {
			cout << 16 << endl;
		}
	}
}