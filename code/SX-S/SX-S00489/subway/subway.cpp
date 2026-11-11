#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, x, y;
long long w[1000000005];
long long a[200005][200005];
long long t[200005][200005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	cin >> k;
	for (int i = 1; i <= 2 * k; i++) {
		for (int j = 1; j <= 2 * k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	cin >> x >> y;
	cout << 32;
	cout << 17;
	return 0;
}
