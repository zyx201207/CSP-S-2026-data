#include <bits/stdc++.h>
using namespace std;
long long a[500009], b[500009];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (long long i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	long long ans = 0, x;
	for (long long i = 1; i <= n; i++) {
		long long k = 0, c = 0;
		for (long long j = i + 1; j <= n; j++) {
			if (k <= m) {
				k = 2 * k + b[j], c++;
			}
		}
		if (c > ans) {
			ans = c, x = i;
		}
		k = 0, c = 0;
		for (long long j = i - 1; j >= 1; j--) {
			if (k <= m) {
				k = 2 * k + b[j], c++;
			}
		}
		if (c > ans) {
			ans = c, x = i;
		}
	}
	for (long long i = 1; i <= n; i++) {
		if (a[i] == a[x]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}