#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long n, m;
long long maxx = LONG_LONG_MIN;
long long minn = LONG_LONG_MAX;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
	}
	long long l = minn, r = maxx;
	long long mid;
	long long sh = 0, maxsh = 0;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		long long tm = 0;
		sh = 0;
		for (long long i = 1; i <= n; ++i) {
			if (a[i] <= mid) {
				tm += mid - a[i];
				sh++;
			}
		}
		if (tm <= m) {
			l = mid + 1;
			maxsh = max(maxsh, sh);
		} else if (tm > m) {
			r = mid - 1;
		}
	}
	cout << maxsh;
	return 0;
}