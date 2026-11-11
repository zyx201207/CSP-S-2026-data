#include <bits/stdc++.h>
using namespace std;
long long yy, y = 1, fl = 1, mmax, g, md, r, l = 1, n, m, a[500005], b[500005], c[500005], mm;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		mm = m;
		fl = 1;
		g = 0;
		yy = 0;
		y = 0;
		l = i;
		r = i;
		md = i;
		while (1) {
			yy = y;
			l--;
			r++;
			b[r] = a[r] - a[i];
			b[l] = a[i] - a[l];
			if (l < 1 && r > n)
				break;
			if (l <= 1) {
				md = r;
				l++;
				y++;
			} else if (r >= n) {
				md = l;
				r--;
			} else {
				if (b[r] >= b[l]) {
					md = l;
					r--;
				} else {
					md = r;
					l++;
					y++;
				}
			}
			if (yy == y) {
				if (mm - b[md] < 0)
					break;
				mm -= b[md];
				g++;
			} else {
				if (mm - y * b[md] < 0)
					break;
				mm -= y * b[md];
				g++;
			}
		}
		mmax = max(mmax, g);

	}
	cout << mmax + 1;
	return 0;
}