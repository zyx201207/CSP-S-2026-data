#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 500005;
ll n, m, a[maxn], cost[maxn];

void sub1() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j < i; j++) {
			cost[i] += a[i] - a[j];
		}
//		cout << cost[i] << '\n';
	}
	ll id = upper_bound(cost + 1, cost + 1 + n, m) - cost - 1;
	printf("%lld", id);
	return ;
}

void sub2() {
	ll l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		ll cost = 0;
		for (ll i = 1; i < mid; i++) {
			cost += (a[mid] - a[i]);
		}
		if (cost > m) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
//		cout << cost << '\n';
	}
	l--;
//	while (a[l] == a[l + 1] && l < n) {
//		l++;
//	}
	printf("%lld", l);
	return ;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (n <= 5000) sub1();
	else sub2();
	return 0;
}
