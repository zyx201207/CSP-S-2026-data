#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, a[N], m;

bool cheak(int mid) {
	for (int i = mid; i <= n; i++) {
		if ((a[i] - a[i - 1])*mid - (a[i] - a[i - mid]) <= m ) {
			return 1;
		}
	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cheak(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
