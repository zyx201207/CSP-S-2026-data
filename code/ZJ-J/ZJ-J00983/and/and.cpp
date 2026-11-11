#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;

ll n, m, mx;
ll a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		mx = max(mx, a[i]);
	}
	if (m == 1)
		printf("%lld", mx);
	else if (m == n) {
		ll ans = a[1];
		for (ll i = 1; i <= n; i++)
			ans &= a[i];
		printf("%lld", ans);
	}
	else if (m == 2) {
		ll ans = 0;
		for (ll i = 1; i <= n; i++)
			for (ll j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		printf("%lld", ans);
	}
	else {
		sort(a+1, a+n+1);
		ll ans = a[n];
		for (ll i = n; i >= n-m+1; i--)
			ans &= a[i];
		printf("%lld", ans);
	}
	return 0;
}
