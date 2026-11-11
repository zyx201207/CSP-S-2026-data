#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000005];
int c[10000005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	int f = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
		}
	}
	sort(a, a + n );
	c[1] = a[1] - a[0];
	for (int i = 2; i < n; i++) {
		c[i] = c[i - 1] + i * (a[i] - a[i - 1]);
	}
	if (c[2] - c[1] == c[3] - c[2]) {
		cout << 1;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (c[i] == m) {
			cout << i + 1;
			return 0;
		} else if (c[i] < m) {
			cout << i + 1 << " ";
			return 0;
		}
	}
	cout << 1;
	return 0;
}
