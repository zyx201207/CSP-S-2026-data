#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll m;
vector<ll> prefixSum;

bool check(ll len, ll target, int r) {
	return len * target - (prefixSum[r] - prefixSum[r - len]) <= m;
}

void solve() {
	ll n;
	cin >> n >> m;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a.begin() + 1, a.end());
	prefixSum.resize(n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		prefixSum[i] = prefixSum[i - 1] + a[i];
		ll target = a[i];
		ll l = 0, r = i;
		while (l < r) {
			ll mid = (l + r + 1) / 2;
			if (check(mid, target, i - 1)) l = mid;
			else r = mid - 1;
		}
		ans = max(ans, l + 1);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	solve();
	return 0;
}
// CODE BY AYACHINENE
// Nyan