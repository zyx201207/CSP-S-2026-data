#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans = 1;

int main() {
	ll a[n], b[n], c[n];
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		c[i] = 1;
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n || m > 0; j++) {
			m--;
			b[i] = a[i] + 1;
			if (b[i] == a[i + j + 1]) {
				c[i]++;
			}
		}
		for (ll j = 0; j < n || m > 0; j++) {
			m--;
			b[i] = a[i] - 1;
			if (b[i] == a[i - j - 1]) {
				c[i]++;
			}
		}
	}
	for (ll j = 0; j < n; j++) {
		ans = max(ans, c[j]);
	}
	cout << ans;
	return 0;
}
