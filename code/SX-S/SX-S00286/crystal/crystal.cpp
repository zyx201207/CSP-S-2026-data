#include <bits/stdc++.h>
using namespace std;
long long m;
long long a[500010];
int n;
bool f1 = 1, f2 = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i)
			f1 = 0;
		if (a[i] - a[i - 1] != a[2] - a[1] && i != 1)
			f2 = 0;
		if (f1 == 0 && f2 == 0)
			break;
	}
	if (f1) {
		int ans = 0;
		for (int i = 1;; i++) {
			ans += i;
			if (ans > m) {
				ans -= i;
				break;
			}
		}
		cout << ans;
		return 0;
	} else if (f2) {
		int ans = 0;
		for (int i = a[2] - a[1];; i += a[2] - a[1]) {
			ans += i;
			if (ans > m) {
				ans -= i;
				break;
			}
		}
		cout << ans;
		return 0;
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		long long x = 0;
		for (int i = 1; i <= mid; i++) {
			x += a[mid] - a[i];
		}
		if (x <= m) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}