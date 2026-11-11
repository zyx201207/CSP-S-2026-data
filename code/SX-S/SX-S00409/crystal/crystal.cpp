#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+100;
long long n, m, a[N], ans = 0, b[N], y, f[N], s = 0, l = 0;

long long ch(long long x) {
	long long sx = m, d = 0;
	for (int i = x - 1; i >= 1; i--) {
		sx = sx - (a[x] - a[i]);
		d++;
		if (sx < 0) {
			return d;
		}
	}
	return x;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	long long f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			f = 1;
		}
	}
	if (n <= 5000) {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			if (ch(i)) {
				ans = max(ans, ch(i));
			}
		}
		cout << ans;
	}

	else if (f == 0) {
		sort(a + 1, a + n + 1);
		long long h;
		h = a[2] - a[1];
		for (int i = 1; i <= n; i++) {
			y = i * (1 + (i - 1) * h + 1) / 2;
			if (y > m) {
				y = i - 1;
				break;
			}
		}
		cout << y;
	} else {
		sort(a + 1, a + n + 1);
		ans = 1;
		s = 0;
		l = 1;
		for (int i = 1; i <= n; i++) {
			if (s + (a[i] - a[i - 1]) * (i - l) <= m) {
				ans++;
				s = s + (a[i] - a[i - 1]) * (i - l);
			} else {
				s = s + (a[i] - a[i - 1]) * (i - l - 1);
				while (s > m) {
					s = s - (a[i] - a[l]);
					l++;
					ans--;
				}
			}
		}
		cout << ans;

	}
	return 0;
}
