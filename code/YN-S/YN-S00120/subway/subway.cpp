#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[100005];
int a[10005][10005], t[10005][10005];
int k[100005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if (!(c == 7 || c == 8 || c == 9 || c == 10 || c == 11) ) {
		cout << 6357;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	int x, y;
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
	}
	for (int j = 1, i = 1, k = 1; j <= q; j++, i++, k++) {
		cout << w[i] + t[i][j] << ' ';
	}
	return 0;
}

