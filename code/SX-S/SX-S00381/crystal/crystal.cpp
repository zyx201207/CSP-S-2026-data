#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long n, m, k, f, d, q;

int check(long long x) {
	long long s = 0;
	for (int i = 1; i <= x; i++) {
		s += a[x] - a[i];
		if (s > d) {

			return 0;
		}
	}

	return 1;
}

int main() {
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	int y = 0;
	for (int i = 1; i <= n; i++) {

		scanf("%lld", &a[i]);
		if (a[i] != a[i - 1] && i != 1) {
			y = 1;
		}
	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (y == 0) {
		if (m == 0) {
			cout << n;
		} else
			cout << n - 1;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	int l = 1;
	int r = n;
	long long mid;
	while (l < r) {
		mid = l + (r - l) / 2 ;
		d = m;
		if (check(mid)) {
			l = mid + 1 ;
		} else {
			r = mid - 1;
		}
	}
	d = m;
	long long e = n;

	for (int i = 1; m > 0; i++) {
		m -= (a[l] - a[i]) ;
		a[i] += (a[l] - a[i]) ;
	}


	while (a[l + 1] == a[l] && l <= n) {

		l++;
	}

	for (int i = 2; i <= e; i++) {
		if (a[i] != a[i - 1]) {
			f = 1;
		}
	}
	if (f == 0) {
		cout << a[e] ;
		return 0;
	}
	cout << l - 1  ;
	return 0;
}
