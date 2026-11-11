#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5;
ll a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll mx = -1;
	if (m = 1) {
		for (ll i = 1; i <= n; i++) {
			mx = max({mx, a[i]});
		}
		cout << mx;
		return 0;
	}
	mx = -1;
	sort(a + 1, a + n + 1);
	ll s = 0, s1 = 0;
	for (ll i = n; i >= n - m; i--) {
		s = a[i];
		s1 = s & a[i - 1];
		mx = max({mx, s1});
	}
	cout << mx;
	return 0;
}