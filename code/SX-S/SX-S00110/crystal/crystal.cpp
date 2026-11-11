#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5000005], mmax = LONG_LONG_MIN, f = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	for (long long i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i - 1])
			f = 0;
	}
	if (f == 1) {
		cout << n;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	while (l <= r) {
		long long mid = (r + l) / 2, cnt = m;
		for (long long i = 1; i < mid; i++) {
			cnt -= a[mid] - a[i];
		}
		if (cnt >= 0) {
			mmax = max(mmax, mid);
			l = mid + 1;
		} else if (cnt < 0) {
			r = mid - 1;
		}
	}
	cout << mmax;
	return 0;
}
//Oct31==Dec25?
