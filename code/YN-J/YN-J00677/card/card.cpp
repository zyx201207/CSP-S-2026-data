#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long N = 5e5;

ll a[N], s[] = {};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll cnt = 0
	for (ll i = 1; i <= n; i++) {
		for (ll i = 1; i <= n - m; i++) {
			s[i] += a[i];
			if (a[i] == s[i]) {
				s[i] = {};
				s[i] += a[i];
			}
		}
		for (ll i = 1; i <= m; i++) {
			if (s[i] == i)
				cnt++;

		}
		cout << cnt << " ";
	}

	return 0;
}