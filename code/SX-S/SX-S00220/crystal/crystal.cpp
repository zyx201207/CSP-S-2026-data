#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], p, b[500005], s = 1000000000005, n1, s1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	p = a[n / 2];
	for (int i = 0; i < n; i++) {
		if (a[i] - p <= s) {
			s = min(s, a[i] - p);
			n1 = i;
		} else if (p - a[i] <= s) {
			s = min(s, p - a[i]);
			n1 = i;
		}
	}
	for (long long i = n1 - 1; i >= 0; i--) {
		if (m <= 0) {
			break;
		}
		if (m >= a[n1] - a[i]) {
			m -= a[n1] - a[i];
			s1++;
		}
	}
	cout << s1;
	return 0;
}
