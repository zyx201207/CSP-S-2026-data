#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long ans = 0;
	cin >> n;
	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> a[i] >> x;
		b[i] = x - 'a';
		ans += a[i];
	}
	long long x = 1, y = 0;
	long long now = 0;
	for (int i = 1; i <= n; i++) {
		if (now + a[i] >= (ans + 1) / 2) {
			x++;
			y = now + a[i] - (ans + 1) / 2 + 1;
			break;
		} else {
			x++;
		}
		now += a[i];
	}
//	cout << x << " " << y << '\n';
	long long l, r;
	int ll, rr;
	if (y == 1) {
		l = a[x - 1];
		r = a[x] - 1;
		ll = x - 1;
		rr = x;
	} else if (y > 1 && y < a[x]) {
		l = y - 1;
		r = a[x] - y;
		ll = x;
		rr = x;
	}
	a[0] = a[n + 1] = 0;
	long long aans = 0;
	while (!(l == 0 && r == 0 && ll == 1 && rr == n  )) {
//		cout << l << " " << r << " " << ll << " " << rr << '\n';
//		cout << 1;
		if (l == 0 || r == 0) {
			if (b[ll] != b[rr]) {
				aans += max(l, r);
			}
			break;
		}
		if (l < r) {
			if (b[ll] != b[rr]) {
				aans += l;
			}
			r -= l;
			a[ll] = 0;
			ll = max(1, ll - 1);
			l = a[ll];

		} else if (l > r) {
			if (b[ll] != b[rr]) {
				aans += r;
			}
			l -= r;
			a[rr] = 0;
			rr = min(n, rr + 1);

			r = a[rr];

		} else {
			if (b[ll] != b[rr]) {
				aans += l;
			}
			a[ll] = 0;
			a[rr] = 0;
			rr = min(n, rr + 1);
			ll = max(1, ll - 1);
			l = a[ll];
			r = a[rr];
		}

	}
	cout << aans;
	return 0;
}
/*/
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
/*/
