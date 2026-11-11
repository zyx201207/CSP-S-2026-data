#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, l, r, a[N];
int pls[N];

signed main() {
	IOS
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		pls[i] = a[i] + pls[i - 1];
	}
	int disum = 0, mid, ans = n;
	while (l <= r) {
		disum = 0, mid = (pls[r] - pls[l - 1]) / (r - l + 1);
		for (int i = l; i <= r; i++) {
			if (disum > m)
				break;
			disum += abs(a[i] - a[r]);
		}
//		cout << mid << ' ' << disum << ' ' << m << '\n';
		if (disum <= m) {
			cout << ans;
			return 0;
		}
		ans--;
//		if (abs(a[l] - mid) > abs(a[r] - mid)) {
//			l++;
//			cout << "l++\n";
//		} else if (abs(a[l] - mid) < abs(a[r] - mid)) {
//			r--;
//			cout << "r--\n";
//		} else {
//			if (abs(a[l + 1] - mid) > abs(a[r - 1] - mid)) {
//				l++;
//				cout << "l++\n";
//			} else {
//				r--;
//				cout << "r--\n";
//			}
//		}
		for (int i = 0; i <= n; i++) {
			if (abs(a[l + i] - mid) > abs(a[r - i] - mid)) {
				l += i + 1;
				break;
			} else if (abs(a[l + i] - mid) < abs(a[r - i] - mid)) {
				r -= i + 1;
				break;
			}
		}
	}
	return 0;
}