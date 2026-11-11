#include <bits/stdc++.h>
using namespace std;
long long a[500005], sum[500005], n, d;
unsigned long long k[500000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	unsigned long long m;
	double ans = 0, c = 1e9+1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 0, uuu = a[2] - a[1];
	for (int i = 3; i <= n; i++)
		if (a[i] - a[i - 1] != uuu)
			l = 1;
	if (l == 0) {
		k[1] = 0;
		for (int i = 2; i <= n; i++)
			k[i] = k[i - 1] + uuu * (i - 1);
		for (int i = 2; i <= n; i++)
			if (k[i - 1] <= m && k[i] > m)
				cout << i - 1 ;
	} else {
		for (int i = 1; i <= n; i++)
			ans += a[i];
		ans = ans / n;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			if (abs(a[i] - ans) <= abs(c - ans)) {
				c = a[i];
				d = i;
			}
		}
		long long q = 1;
		while (m > 0) {
			for (int i = d - 1; i >= 1; i--) {
				if (m - (c - a[i]) >= 0) {
					m = m - (c - a[i]);
					a[i] = c;
					sum[q]++;

				} else
					break;
			}
			if (m > 0) {
				c = a[d + 1];
				d += 1;
				q++;
			}
		}
		long long jg = -1;
		for (int i = 1; i <= q; i++)
			if (sum[i] > jg)
				jg = sum[i];
		cout << jg + 1;
	}
	return 0;
}
