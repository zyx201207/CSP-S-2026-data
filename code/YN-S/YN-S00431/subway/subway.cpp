#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1e5 + 5;
int c, n, m, w[520], d, q, a[520][N], t[520][N], x[M], y[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		long long ans = w[x[i]] + w[y[i]];
		for (int j = x[i]; j < y[i]; j++)
			ans += (t[j][j] + t[j][j + 1]);
		cout << ans << '\n';
	}
	return 0;
}