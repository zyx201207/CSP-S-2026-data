#include <bits/stdc++.h>
using namespace std;
int w[10000005], k[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> k[i];
	}

	int x, y;

	for (int i = 1; i <= q; i++) {

		cin >> x >> y;
		cout << w[x] + w[i] + w[y] + k[i] << endl;
	}

	return 0;
}