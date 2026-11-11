#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], c[500005];
int n, m, sum = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		c[i] = c[i - 1] + a[i] - a[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		if (c[i] <= i) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
