#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005], a[505][505], t[505][505], b[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++) {
		ll j;
		cin >> j;
		for (ll k = 1; k <= j; k++) {
			cin >> a[i][k] >> t[i][k];
			if (b[a[i][k]] == 0) {
				b[a[i][k]] = t[i][k];
			}
		}
	}
	while (q--) {
		ll x, y, sum = 0;
		cin >> x >> y;
		sum += w[x] + w[y];
		sum += b[x] + b[y];
		cout << sum << "\n";
	}
	return 0;
}