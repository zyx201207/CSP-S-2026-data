#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	const int M = 3e5;
	int n, m, a[M];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		int q = -1e9;
		for (int i = 1; i <= n; i++)
			q = max(a[i], q);
		cout << q;
		return 0;
	}
	if (m == n) {
		int q = a[1];
		for (int i = 1; i <= n; i++)
			q = q & a[i];
		cout << q;
		return 0;
	}
	if (m == 2) {
		int ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int q = a[i] & a[j];
				ans = max(ans, q);
			}
		}
		cout << ans;
		return 0;
	}
	int x = -1;
	if (m == n - 1) {
		int c[M], d[M];
		c[1] = a[1], d[n] = a[n];
		for (int i = 2; i < n; i++) {
			c[i] = c[i - 1] & a[i];
			d[n - i + 1] = d[n - i] & a[n - i + 1];
		}
		x = max(c[n - 1], d[2]);
		for (int i = 2; i < n; i++) {
			int p = c[i - 1] & d[i + 1];
			if (p > x)
				p = x;
		}
	}
//	if (x != 1) {
//		printf("%d", x);
//		return 0;
//	}


	sort(a + 1, a + 1 + n);
	int ans = a[n];
	for (int i = n; i >= n - m + 1; i--) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}