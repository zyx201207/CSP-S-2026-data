#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[503305];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	ll ans = 1;
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n > 5000) {
		for (int i = 1; i <= n; ++i) {
			ll sum = (a[1] + a[i]) * i / 2;
			if (sum > m) {
				ans = i;
				break;
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			ll sum = 0;
			for (ll j = i - 1; j >= 0; --j) {
				sum += a[i] - a[j];
				if (sum > m) {
					// cout << i << " " << j << " " << sum << " shanyichun\n";
					ans = max(ans, i - j);
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}