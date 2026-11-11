#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll n, m;
ll a[N], sum[N];
ll ans;
bool check (int x) {
	for (int i = x; i <= n; i++) {
		ll s = a[i] * (x - 1);
		int l = i - x + 1;
		ll res = s - (sum[i - 1] - sum[l - 1]);
		if (res <= m) return true;
	}
	return false;
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
