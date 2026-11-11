#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];
long long ans = 0;
bool f1 = 1;
bool f2 = 1;
long long x;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (long long i = 0; i < n; i++) {
		if (i == 1) {
			x = a[i] - a[i - 1];
		}
		if (a[i] != i + 1)
			f1 = 0;
		if (i != 1 && a[i] - a[i - 1] != x)
			f2 = 0;
	}
	if (f1) {
		long long y = sqrt(2 * m) + 0.5;
		cout << y;
		return 0;
	}
	if (f2) {
		long long xx = 1;
		bool ff = 1;
		while (ff) {
			if (xx * (xx + x) <= m && (xx + 1) * (xx + 1 + x) >= m)
				ff = 0;
			else
				xx++;
		}
		cout << xx + 1;
		return 0;
	}

	for (long long i = 1; i < n; i++) {
		long long x_ = 0, xx_ = 0;
		for (long long j = i; j >= 0; j--) {
			xx_ += (a[i] - a[j]);
			if (xx_ > m)
				break;
			else
				x_++;
		}
		ans = max(ans, x_);
	}
	cout << ans << endl;
	return 0;
}
