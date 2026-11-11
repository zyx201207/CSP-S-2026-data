#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200005], mx = LLONG_MIN, x = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = n; i >= 1; i--) {
		x = a[i - m + 1];
		for (ll j = i - m + 1; j <= i; j++) {
			x = x & a[i];
		}
		mx = max(x, mx);
	}
	cout << mx;
}