#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, ans, a[N], l, r, mid;

bool f(int num) {
	int res = 0;
	for (int i = 1; i < num; i++) {
		if (a[i] > num) {
			return res <= m;
		}
		res += a[num] - a[i];
	}
	return res <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	r = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	while (l <= r) {
		mid = (l + r) >> 1;
		if (f(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
