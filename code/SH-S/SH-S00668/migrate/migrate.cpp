#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 2000025;
ll c, t;
ll n, d, x[maxn], f[maxn];
vector <ll> v[maxn];
ll lessthan(ll a) {
	if (x[1] >= a) return 0;
	ll l = 1, r = n, mid;
	while (l != r) {
		if (x[mid = (l + r + 1) >> 1] >= a) r = mid - 1;
		else l = mid;
	}
	return l;
}
void solve() {
	ll res = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> x[i];
	for (int i = 1; i <= n; ++ i) {
		ll pv = lessthan(x[i] - d) + 1;
		if (pv == 1) continue;
		if (i - pv < 2) continue;
		ll l = lessthan(x[pv + 1] - d) + 1;
		if (l == 1) continue;
		ll r = lessthan(x[pv + 2] - d);
		for (int j = l; j <= r; ++ j) {
			f[i] ++;
			v[i].push_back(j);
		}
		
		res += f[i];
	}
	cout << res << '\n';
}
void solve2() {
	ll res = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> x[i];
	for (int i = 1; i <= n; ++ i) {
		ll pv = lessthan(x[i] - d) + 1;
		if (pv == 1) continue;
		if (i - pv < 2) continue;
		ll l = lessthan(x[pv + 1] - d) + 1;
		if (l == 1) continue;
		ll r = lessthan(x[pv + 2] - d);		
		res += r - l + 1;
	}
	cout << (res ? res + 1 : 0) << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		//if (c == 11 || c == 12) 
		solve2();
		//else solve();
	}
	return 0;
}

