#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crtstal.out", "w", stdout);
	int a[i], dp[i][i];
	int a, n, m, ans = 0;
	cin >> a >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 0; i < n; i++) {
		dp[i][i] == a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == 4) {
				cout << a[i];
				ans + 1;
			}
		}
	}
	return 0;
}