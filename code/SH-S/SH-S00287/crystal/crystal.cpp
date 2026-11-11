#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+5;
ll n, m;
ll a[maxn], sum[maxn];
ll gets(ll l, ll r) {
	return sum[r] - sum[l-1];
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	} 
	ll ans = 1;
	for (int i = 2; i <= n; i++) {
		ll l = 1, r = i-1, Ans = 0;
		while (l <= r) {
			ll mid = (l+r) >> 1;
			if (m-mid*a[i]+gets(i-mid, i-1) >= 0) {
				Ans = mid;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		ans = max(ans, Ans+1);
	}
	cout << ans << '\n';
	return 0;
}
