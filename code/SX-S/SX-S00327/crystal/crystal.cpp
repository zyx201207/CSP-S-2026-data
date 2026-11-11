#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define st string
using namespace std;
ll n, m;
ll a[500010];

int main() {
	fast;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	int u1 = 0, u2 = 0, u3 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			u1 = 1;
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			u2 = 1;
		}
		if (i >= 2 && a[i] != a[i - 1]) {
			u3 = 1;
		}
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			u2 = 1;
		}
	}

	if (u3 == 0) {
		cout << n;
		return 0;
	}
	if (u1 == 0) {
		ll ans = 0;
		ll h = 0;
		for (ll i = 1; i < n; i++) {
			h += i;
			ans++;
			if (h > m) {
				cout << ans;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	if (u2 == 0) {
		ll ans = 0;
		ll h = 0;
		ll cz = abs(a[2] - a[1]);
		for (ll i = 1; i <= n - 1; i++) {
			h += cz * i;
			ans++;
			if (h > m) {
				cout << ans;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	ll ans = 1;
	for (ll i = n; i > 1; i--) {
		ll h = 0;
		ll sum = 0;
		for (ll j = i - 1; j >= 1; j--) {
			h += a[i] - a[j];
			sum++;
			if (h > m) {
				ans = max(ans, sum);
				break;
			}
		}
		if (h <= m) {
			ans = max(ans, i);
		}
	}
	cout << ans ;
	return 0;
}