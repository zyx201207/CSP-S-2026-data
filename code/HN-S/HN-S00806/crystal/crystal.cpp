#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

const int N = 5e5 + 5;

ll n, m, a[N], sum[N], ans = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (ll i = 2; i <= n; i++) {
		// 求最小的x,使得(i-x)*a[i]-sum(x~(i-1))<=m
		ll l = 0, r = i;
		while (l + 1 < r) {
			ll mid = l + r >> 1;
			if ((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}

