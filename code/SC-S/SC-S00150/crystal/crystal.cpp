#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, ans = 0;
ll m;
ll a[N], pre[N];
bool check (ll x, ll i) {
	return (i - x + 1) * a[i] - (pre[i] - pre[x - 1]) <= m;
}
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - r);
//		ll sum = 0, cnt = 0;
//		for (int j = i; j >= 1; --j) {
//			if (sum + a[i] - a[j] <= m) {
//				sum += a[i] - a[j];
//				++cnt;
//			}
//			else {
//				break;
//			}
//		}
//		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
// O(nlogn), 100pts
