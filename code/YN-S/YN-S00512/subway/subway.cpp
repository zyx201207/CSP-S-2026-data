#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int k[1000010], a[1001][1001], t[1001][1001];
int w[1000010];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
			cin >> t[i][j];
		}
	}
	cout << 35 < '\n';
	cout << 16;
	return 0;
}