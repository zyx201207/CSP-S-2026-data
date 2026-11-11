#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n;
	long long m, ans = LLONG_MIN, l = LLONG_MIN;
	cin >> n >> m;
	bool p = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = max(l, abs(a[i]));
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i < n; i++) {
		if (a[i + 1] - a[i] != a[i] - a[i - 1])
			p = 1;
	}
	if (p == 0) {
		ans = floor(sqrt(m  * 2 / (a[2] - a[1])));
		cout << ans;
		return 0;
	}
	if (l <= 100) {
		for (int i = 1; i <= 100; i++) {
			long long j = upper_bound(a + 1, a + n + 1, i) - a - 1, d = m, s = 0;
			while (d >= 0 && j > 0) {
				d = d - (i - a[j]);
				if (d < 0)
					break;
				s++;
				j--;
			}
			ans = max(ans, s);
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		long long j = i - 1, d = m, s = 1;
		while (d >= 0 && j > 0) {
			d = d - (a[i] - a[j]);
			if (d < 0)
				break;
			s++;
			j--;
		}
		ans = max(ans, s);
	}
	cout << ans;
	return 0;
}/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/