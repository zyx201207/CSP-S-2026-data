#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], b[N];
int n, m;

bool check(int x) {
	int sum = 1e18 + 5;
	for (int i = x; i <= n; i++) {
		int y = b[i] - b[i - x - 1];
		if (a[i]*x >= y) {
			sum = min(sum, a[i] * x - y);
		}
	}
	return sum <= m;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int minn = 1e18 + 5;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	if (minn < 0) {
		for (int i = 1; i <= n; i++) {
			a[i] -= minn + 1;
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}