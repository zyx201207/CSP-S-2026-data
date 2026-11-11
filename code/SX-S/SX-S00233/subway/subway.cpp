#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 2e5+5, N = 505, Q = 1e5+5;
int c, n, m, d, q, w[M], k[N], a[N][M], t[M], x[M], y[M], ans;

void solveA() {
	return ;
}

void solveB(int i) {
	for (int j = x[i]; j <= y[i]; j++) {
		ans = ans + t[j];
	}
	return ;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[a[i][j]];
		}
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		cin >> x[i] >> y[i];
		ans = ans + w[x[i]] + w[y[i]];
		if (c >= 7 && c <= 11) {
			solveA();
		}
		if (c >= 12 && c <= 19) {
			solveB(i);
		}
		cout << ans << endl;
	}
	return 0;
}
