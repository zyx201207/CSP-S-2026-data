#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[100005], f, mmax;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = -1e15;
	ll p = a[2] - a[1];
	for (ll i = 2; i < n; i++)
		if (a[i + 1] - a[i] != p)
			f = 1;
	if (!f) {
		for (ll i = 1; i <= n; i++)
			if (i * (i + 1) / 2 * p > m) {
				cout << i;
				break;
			}
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (ll i = 2; i <= n; i++) {
		ll s = 0;
		for (ll j = i - 1; j >= 0; j--) {
			s += a[i] - a[j];
			if (s > m) {
				mmax = max(mmax, i - j);
				break;
			}
		}
	}
	cout << mmax;
	return 0;
}