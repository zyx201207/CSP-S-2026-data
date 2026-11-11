#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n, m, d, q, x, y, ans, l;
ll w[500005], k[500005], a[105][500005];
ll t[105][500005];

int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;

	for (ll i = 1; i <= m; i++) {

		cin >> w[i];
	}

	for (ll i = 1; i <= n; i++) {

		cin >> k[i];

		for (ll j = 1; j <= k[i]; j++) {

			cin >> a[i][j] >> t[i][j];
		}
	}



	for (ll r = 1; r <= q; r++) {

		cin >> x >> y;
		ans = w[x] + w[y];

		if (a[x][y]) {
			ans += t[x][x] + t[y][y];
		}

		cout << ans << endl;
	}

	return 0;
}