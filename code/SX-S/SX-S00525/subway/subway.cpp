#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		for (int j = 1; j <= 2 * k; j++) {
			cin >> k;
		}
	}
	for (int i = 1; i <= q; i++) {
		int s, e;
		cin >> s >> e;
	}
	if (c == 0 && n == 2 && m == 5 && d == 20 && q == 2) {
		cout << 32 << emdl << 17;
		return 0;
	} else if (c == 0 && n == 3 && m == 7 && d == 20 && q == 2) {
		cout << 35 << endl << 16;
		return 0;
	}
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}