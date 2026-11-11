#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n;
	cin >> n;
	
	ll a[n + 1];
	char c[n + 1];
	for (ll i = 1; i <= n; ++ i) {
		cin >> a[i] >> c[i];
	}
	
	ll l = 1, r = n, ans = 0;
	while (l < r) {
		if (c[l] == c[r]) {
			ll mi = min(a[l], a[r]);
			a[l] -= mi;
			a[r] -= mi;
		} else {
			ll mi = min(a[l], a[r]);
			a[l] -= mi;
			a[r] -= mi;
			
			ans += mi;
		}
		
		if (a[l] == 0) ++ l;
		if (a[r] == 0) -- r;
	}
	
	cout << ans << "\n";
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll T = 1;
	while (T --) solve();
	return 0;
}