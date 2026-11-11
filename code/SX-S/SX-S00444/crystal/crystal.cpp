#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N], b[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, ff = 1, zh = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 2)
			zh = a[i] - a[i - 1];
		if (i > 2 && (a[i] - a[i - 1]) != zh)
			ff = 0;
	}
	if (ff == 1) {
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			m -= zh;
			if (m > 0)
				ans++;
		}
		cout << ans;
		return 0;
	}
	long long ans = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i] - a[i - 1];
	sort(b + 1, b + n + 1);
	long long q = b[(n + 1) / 2];
	long long l = b[(n + 1) / 2 - 1], r = b[(n + 1) / 2 + 1], i = 2, j = 2;
	while (m >= 0) {
		if (abs(q - l) <= abs(q - r)) {
			m -= abs(q - l);
			ans++;
			l = b[(n + 1) / 2 - i];
			i++;
		} else {
			m -= abs(q - r);
			ans++;
			r = b[(n + 1) / 2 + j];
			j++;
		}
	}
	cout << ans ;
	return 0;
}
