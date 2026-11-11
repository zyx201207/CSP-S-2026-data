#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, res, tot;
int a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i], tot += a[i];
	int l = 0, r = n + 1, ls = 0, rs = tot + 1;
	while (l < r) {
		if (tot - ls + 1 <= rs) {
			r--;
			rs -= a[r];
			if (c[l] != c[r]) {
				if (tot - ls + 1 >= rs) {
					res += a[r] - (tot - ls + 1 - rs);
				} else
					res += a[r];
			}
		} else {
			l++;
			ls += a[l];
			if (c[l] != c[r]) {
				if (tot - ls + 1 < rs) {
					res += a[l] - (rs - (tot - ls + 1));
				} else
					res += a[l];
			}
		}
	}
	cout << res;
	return 0;
}