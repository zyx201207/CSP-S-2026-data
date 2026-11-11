#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans, l1, r1;
int a[500055], que[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 0, r = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		while (-1 * (sum - a[i] * (r - l + 1)) > m) {
			sum -= a[l];
			l++;
			//	cout << l << " " << r << endl;
		}
		sum += a[i];
		r++;
		//	cout << l << " " << r << endl;
		//cout << sum << endl;
		if (ans < r - l + 1) {
			ans = r - l + 1;
			//	l1 = l;
			//	r1 = r;
		}

	}
	cout << ans << endl;
//	cout << l1 << " " << r1;
	return 0;
}