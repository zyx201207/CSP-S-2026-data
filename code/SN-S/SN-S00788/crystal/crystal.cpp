#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], sum[N];
bool check(ll x, ll rt) {
	int len = rt - x + 1;
	ll need = a[rt] * len - (sum[rt] - sum[rt - len]);
	return need <= m;
}
int main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll ans = LLONG_MIN;
	for (int i = n; i >= 1; i--) {
		if (i <= ans) break;
		ll l = 1, r = i + 1, res;
		while (l < r) {
			int mid = l + (r - l >> 1);
			if (check(mid, i)) {
				r = res = mid;
			} else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	} 
	cout << ans;
	return 0;
}
