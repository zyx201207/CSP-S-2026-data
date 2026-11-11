#include <bits/stdc++.h>//Chinese can fly !
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], ans, f[N], d[N];

bool sephiroth(int x) {
	for (int i = x; i <= n; i++) {
		if (f[i] - (i - x)*a[i] + d[i - x] <= m) {
//			cout << f[i] << "\n";
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
	sort(a + 1, a + n + 1);
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
		f[i] = f[i - 1] + (i - 1) * (a[i] - a[i - 1]);
//		cout << f[i] << " ";
	}
	int l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (sephiroth(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/