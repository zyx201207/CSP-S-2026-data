#include <bits/stdc++.h>
using namespace std;
int const N = 5e5+10;
long long a[N], b[N], n, m;

int check(long long k) {
	for (int i = k; i <= n; i++) {
		if (b[i] - b[i - k] + m >= a[i]*k)
			return 1;
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long l = 1, r, mid = 0, ans = 0, flg = 0, fl = 0;
	cin >> n >> m;
	r = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			flg = 1;
	}
	long long ui = a[2] - a[1], jk = 0;
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != ui) {
			fl = 1;
		}
	}
	if (flg && fl)
		sort(a + 1, a + n + 1);
	if (fl == 0) {
		if (a[1] > a[2]) {
			for (int i = 1; i <= n / 2; i++) {
				jk = a[i];
				a[i] = a[n - i + 1];
				a[n - i + 1] = jk;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	while (l <= r) {
		mid = (l + r ) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}