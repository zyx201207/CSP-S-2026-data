#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 5e5 + 5, inf = 1e18;
ll tc = 1, n, m, a[N], pre[N];

ll calcsum(ll l, ll r) {
	if (l > r) {
		return 0;
	}
	return pre[r] - pre[l - 1];
}

bool chk(ll len) {
	for (ll l = 1; l <= n; l++) {
		ll r = l + len - 1;
		if (r > n) {
			break;
		}
		if (len * a[r] - calcsum(l, r) <= m) {
			return 1;
		}
	}
	return 0;
}

void solve() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	ll l = 1, r = n, res = -1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (chk(mid)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld\n", res);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	while (tc--) { solve(); }
	return 0;
}