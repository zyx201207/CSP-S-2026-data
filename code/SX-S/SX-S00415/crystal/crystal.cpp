#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N], v[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, k, su = 0, p, f = 0, maxs = LLONG_MIN, mm;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	k = a[n] - a[n - 1];
	for (int i = 1; i < n; i++) {
		if (a[i] + k != a[i + 1]) {
			f = 1;
			break;
		}
	}
	if (f == 0) {
		p = 0;
		while (m >= 0) {
			p += k;
			m -= p;
			if (m >= 0)
				su++;
			m -= p;
			if (m >= 0)
				su++;
		}
		cout << su + 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		mm = m;
		su = 0;
		for (int j = 1; j <= n; j++)
			s[j] = abs(a[i] - a[j]);
		sort(s + 1, s + n + 1);
		for (int j = 1; j <= n; j++) {
			if (mm - s[j] >= 0) {
				su++;
				mm = mm - s[j];
			}
		}
		maxs = max(maxs, su);
	}
	cout << maxs;
	return 0;
}
