#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int NN = 1e3+10;
long long a[NN][NN], t[NN][NN];
long long n, m, c, d, q, w[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		long long x, y;
		cin >> x >> y;
		long long ans = 0;
		ans += w[x];
		ans += w[y];
		ans += t[1][1];
		ans += t[1][1];
		cout << ans << "\n";
	}
	return 0;
}