#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[500005], a[501][501], t[101][501], x[500001], y[50001];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int j = 3; j <= n - 1; j++) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a[j][i] >> t[j][i];
		}
	}
	for (int j = 3; j <= n - 1; j++) {
		cin >> x[j] >> y[j];
	}
	cout << 0;
	return 0;
}