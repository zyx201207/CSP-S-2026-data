#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	for (ll x = 0; x < (1LL << n); x++) {
		ll cnt = 0;
		for (ll i = 0; i < n; i++) {
			if (x & (1LL << i))
				cnt++;
		}
		ll f = (1LL << n) - 1;
		if (cnt == m) {
			for (ll i = 0; i < n; i++) {
				if (x & (1LL << i)) {
					f &= a[n - i - 1];
				}
			}
		}
		ans = max(ans, f);
	}
	cout << ans;
	return 0;
}