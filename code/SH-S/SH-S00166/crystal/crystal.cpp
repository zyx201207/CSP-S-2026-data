#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, a[500010], ans=-1, pre[500010];

ll calc(ll x, ll len) {
	//printf("calc(%lld,%lld)=%lld\n", x, len, (a[x] * (len - 1) - (pre[x-1] - pre[x-len])));
	return (a[x] * (len - 1) - (pre[x-1] - pre[x-len]));
}

ll solve(ll x) {
	//printf("solving %lld\n", x);
	ll L = 1, R = x;
	while (L < R) {
		ll mid = (L + R + 1) / 2;
		if (calc(x, mid) > m) R = mid - 1;
		else {
			L = mid;
		}
	}
	//printf("L=%lld\n", L);
	return L;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (ll i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (ll i=1; i<=n; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	
	for (ll i=1; i<=n; i++) {
		ll r = solve(i);
		if (r > ans) ans = r; 
	} 
	
	cout << ans;
	
	return 0;
} 
