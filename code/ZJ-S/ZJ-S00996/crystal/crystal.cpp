#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;

ll n, m, ans = 1;
ll a[N], d[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for (ll i = 1; i <= n; i++)
		d[i] = a[i]- a[i-1];
	if (n <= 5000) {
		for (ll i = 1; i <= n; i++) {
			ll tot = m, cnt = 1;
			for (ll j = i+1; j <= n; j++) {
				if (tot >= d[j]*(j-i)) {
					cnt++;
					tot -= d[j] * (j - i);
				}
				else
					break;
			}
			ans = max(cnt, ans);
		}
		printf("%lld", ans);
	}
	else {
		ll tot = 0;
		for (ll i = 2; i <= n; i++) {
			tot += d[i] * (i-1);
			if (tot > m) {
				printf("%lld", i-1);
				return 0;
			}
		}
		printf("%lld", n);
	}
	return 0;
}
