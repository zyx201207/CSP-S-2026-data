#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
int n, a[N], ans;
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	int x1 = a[1], x2 = a[n];
	while (l < r) {
		int w = min(x1, x2);
		x1 -= w, x2 -= w;
		if (c[l] != c[r]) {
			ans += w;
		}
		if (x1 == 0) {
			l++;
			x1 += a[l];
		}
		if (x2 == 0) {
			r--;
			x2 += a[r];
		}
	}
	cout << ans;
	return 0;
}
