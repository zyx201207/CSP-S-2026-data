#include <bits/stdc++.h>
using namespace std;

int n, m, a[200050], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		sort (a + 1, a + n + 1);
		cout << a[n];
	}
	sort (a + 1, a + n + 1);
	ans = (a[n] & a[n - 1]);
	for (int i = 1; i < m - 1; i++) {
		ans = ans & a[n - i - 1];
	}
	if (ans == 0) {
		ans = (a[n - 1] & a[n - 2]);
		for (int i = 1; i < m - 1; i++) {
			ans = ans & a[n - i - 2];
		}
	}
	cout << ans;
	return 0;
}