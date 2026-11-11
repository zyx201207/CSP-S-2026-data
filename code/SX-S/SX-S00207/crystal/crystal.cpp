#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m, a[500005], sum[500005];
ll l, r, mid, ans;

ll getsum(ll l, ll r) {
	return l > 0 ? sum[r] - sum[l - 1] : sum[r];
}

ll check(ll len) {
	ll iflaw = 0;
	
	for (ll i = 0; i + len - 1 < n; i++) {
		ll right = i + len - 1;
		ll sumval = getsum(i, right - 1);
		ll sub = a[right] * (len - 1) - sumval;
		
		if (sub <= m) {
			iflaw = 1;
			break;
		}
	}
	
	return iflaw;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	sort(a, a + n);
	
	sum[0] = a[0];
	
	for (ll i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	l = 1, r = n;
	
	while (l <= r) {
		mid = (l + r) / 2;
		
		if (check(mid)) {
			ans = mid;
			
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}