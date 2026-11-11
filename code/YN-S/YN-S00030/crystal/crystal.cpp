#include <bits/stdc++.h>
using namespace std;

long long n, m, z, z2, mi = 1e9, ans = 1;
long long a[500005], b[500005], c[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		z += a[i];
	}
	for (long long i = 1; i <= n; i++) {
		for (long long y = 1; y <= n; y++) {
			mi = min(mi, a[y]);
		}
		c[i] = mi;
		for (long long y = 1; y <= n; y++) {
			if (a[y] == mi) {
				a[y] = 1e9;
				break;
			}
		}
		mi = 1e9;
	}
	if (n % 2 == 0) {
		z2 = n / 2;
	} else {
		z2 = n / 2 + 1;
	}
	z = c[n / 2 + 1];
	for (long long i = 1; i <= n; i++) {
		b[i] = z - c[i];
	}
	for (long long i = 1; i <= z2 ; i++) {
		if (b[z2 - 1] <= - b[z2 + 1]*ans) {
			if (m > b[z2 - 1]) {
				m -= b[z2 - 1];
				ans++;
				for (long long y = z2 - 1; y >= 1; y--) {
					b[y] = b[y - 1];
				}
			}
		} else {
			if (m >= - b[z2 + 1]*ans) {
				m += b[z2 + 1] * ans;
				ans++;
				for (long long y = z2 + 1; y <= n; y++) {
					b[y] = b[y + 1];
				}
			}
		}
	}
	cout << ans + 1;
	return 0;
}