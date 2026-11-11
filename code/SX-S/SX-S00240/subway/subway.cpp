#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int c, n, m, d, q;
int w[N];
int a[505][N], t;
int k[505];
int x, y;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		int ans = 0;
		ans += w[x] + w[y] + 2 * t;
		cout << ans << '\n';
	}
	return 0;
}
//rp++
