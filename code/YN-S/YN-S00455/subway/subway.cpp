#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, x, y;
bool b[80050][550];
int w[500050], k[500], a[80050][550];

int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x;
			cin >> a[x][i];
			b[x][i] = 1;
		}
	}
	while (q--) {
		cin >> x >> y;
		cout << a[x][y] << "\n";
	}
	return 0;
}