#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 100025;
ll n, m;
vector <ll> a;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> n >> m;
	ll t;
	for (int i = 0; i < n; ++ i) {
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	ll ans = 1;
	ll l = 0, sum = a[0];
	for (ll r = 1; r < n; ++ r) {
		sum += a[r];
		while (a[r] * (r - l + 1) - sum > m) {
			sum -= a[l++];
		}
		ans = max(r - l + 1, ans);
		//cerr << l << ' ' << r << ' '<<r - l + 1<<'\n';
	}
	cout << ans;
	return 0;
}

