#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n, m;
bool chk(int x) {
	int now = 0;
	for (int i = 1; i < x; i++) {
		now += a[x] - a[i];
	}
	for (int i = x; i <= n; i++) {
		if (now <= m) return 1;
		now -= (a[i] - a[i - x + 1]);
		now += (x - 1) * (a[i + 1] - a[i]);
	}
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (chk(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
