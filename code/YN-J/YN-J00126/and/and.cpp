#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b) {
	return a < b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n], ans = -1;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	long long k = a[n - 1];
	bool ok = true;
	for (int i = 1; i <= m; i++) {
		if (a[n - i] == k) {
			ok = true;
		} else {
			ok = false;
			break;
		}
	}
	if (ok) {
		cout << k;
		return 0;
	}
	long long s = 0;
	for (long long i = 0; i < n; i++) {
		s = a[i];
		if (i >= m)
			for (long long j = 1; j < m; j++)
				s = s & a[i - j];
		ans = max(ans, s);
	}
	cout << ans;
	return 0;
}