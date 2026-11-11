#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 10;
const int M = 5e5 + 10;
const int K = 5e5 + 10;
int c, n, m, d, q, a[M], k, b[N][K];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	while (q--) {
		int ans = 0;
		cin >> k;
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= 2 * k; i++) {
				cin >> b[j][i];
				ans += b[j][i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
