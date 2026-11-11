#include <bits/stdc++.h>
using namespace std;
long long n, m, mid, l = 1, r, a[500010], ans = 1, s1, s2, s3, q = 1, b[500010];

int check(long long k) {
	long long s = 0;
	for (int i = 1; i < k; i++) {
		s = s + a[k] - a[i];
		if (s > m) {
			return 0;
		}
	}
	return 1;
}

int pd(int k) {
	for (int i = k; i <= n; i++) {
		if (b[i] - b[i - k] + m >= a[i]*k) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	l = ans;
	r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (pd(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
