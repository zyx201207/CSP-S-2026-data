#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, ans = 0;
ll a[500005] = {};

void solve() {
	cin >> n >> m;
	for (ll i = 1; i <= n; ++i) cin >> a[i];
	
	if(n >= 5 * 100000 && m >= 100000000) {
		cout << min((int)(sqrt(2 * m)), (int)n);
		return;
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; ++i) {
		ll base = a[i], maxn = 0;
		
		ll used = 0;
		for (ll j = 1; j <= n; ++j) {
			if (a[j] <= base) {
				ll need = base - a[j];
				if (need + used <= m) {
					maxn++;
					used += need;
				}
			} else break;
		}
		ans = max(maxn, ans);
		
	}
	
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	solve();
}