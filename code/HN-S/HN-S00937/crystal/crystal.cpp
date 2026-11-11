#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 5e5 + 10;

int a[kMaxN], st[kMaxN], n, m, ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		st[i] = st[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		for (; l < r;) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (st[i] - st[mid - 1]) <= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
