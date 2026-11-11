#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], s[N], ans, k;
bool flag = 1; 
bool check(int l, int r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m;
}
void sub() {
	int l = 1, r = n, res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mid * (mid - 1) * k <= 2 * m) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << res; 
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2) {
			k = a[i] - a[i - 1];
		}
		if (flag && i > 2) {
			if (a[i] - a[i - 1] != k) flag = 0;
		}
	}
	if (flag) {
		sub(); 
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i; 
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, i)) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	cout << ans; 
	return 0;
}
