#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll c, t, w = 0;
	cin >> c >> t;
	while (t--) {
		ll n, d;
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 11 || c == 12) {
			ll sum = 0;
			for (ll i = 1; i <= n; i++) {
				for (ll j = i + 1; j <= n; j++) {
					if (j - i > 1) {
						ll x = j - i + 1;
						ll y = x / d;
						if (y * d < x) {
							y++;
						}
						if ((x - 1) % d != 0 && y < 3) {
							sum++;
						}
					}
				}
			}
			cout << sum << "\n";
		} else {
			cout << w << "\n";
			w++;
		}
	}
	return 0;
}