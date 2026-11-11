#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int lz = INT_MIN;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i; j <= m; j += m - 1) {
			sum &= a[i] &= a[j];
		}
		ans = max(sum, lz);
		if (ans == sum) {
			lz = sum;
		}
	}
	cout << ans;
	return 0;
}