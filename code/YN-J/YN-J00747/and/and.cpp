#include <bits/stdc++.h>
using namespace std;
int a[200010];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	if (n == m) {
		int ans = a[1];
		for (int i = 1; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	int ans = a[n];
	for (int i = n; i > n - m; i--) {
		ans &= a[i];
	}
	cout << ans;
	return 0;
}