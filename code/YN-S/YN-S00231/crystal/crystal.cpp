#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005];
int d[500005];
int l, r;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + a[i] - a[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		l = 1, r = n;
		while (r - l >= i) {
			if (a[l + 1] - a[l] > a[r] - a[r - 1]) {
				l++;
			} else {
				r--;
			}
		}
		if (d[r] - d[l]  <= m) {
			cout << i;
			return 0;
		}
	}
	return 0;
}