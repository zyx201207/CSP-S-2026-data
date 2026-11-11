#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const ll maxn = 2e6 + 5;
ll c , t;
ll a[maxn];
vector <ll> hx;

void solve () {
	ll n , d;
	cin >> n >> d;
	cin >> a[1];
	for (ll i = 2; i <= n; i++) {
		cin >> a[i];
		a[i] -= a[1];
	}
	a[1] = 0;
	ll cz = a[2] - a[1];
	ll cnt = 0;
	for (ll i = 2; i <= n; i++) {
		if (a[i] - a[1] <= d) {
			cnt++;
		} else {
			break;
		}
	}
//	cout << cnt << "\n";
	for (ll i = 1; i <= cnt - 1; i++) {
		hx.push_back(cnt * cz + i * cz);
//		cout << cnt * cz + i * cz << "  ";
	}
//	cout << "\n";
	ll ans = 0;
	for (auto j : hx) {
		for (ll i = 0; i <= ((a[n] - j) / cz); i++) {
			ans++;
		}
	}
	cout << ans / 2 << "\n";
}

int main () {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c , t;
	cin >> c >> t;
	if (c == 0 || c == 11 || c == 12) {
		while (t--) solve();
	}
	return 0;
}
