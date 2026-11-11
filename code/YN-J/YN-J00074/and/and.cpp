#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, a[N], b[N], maxi, dp[2002][2002] = {};

int main() {
	freopen("and5.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] & a[i];
		maxi = max(maxi, a[i]);
	}
	if (m == 1) {
		cout << maxi;
		return 0;
	}
	if (m == n) {
		cout << b[n];
		return 0;
	}
	maxi = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			maxi = max(maxi, a[i] & a[j]);
	cout << maxi;
	return 0;
}