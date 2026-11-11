#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010];
long long x, c, p, ans; //x¼ÇÂ¼ÏÂ±ê

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p += a[i];
	}

	if (n % 2 == 0) {
		p /= n;
		for (int i = 1; i <= n; i++) {
			if (abs(a[i] - p) < c) {
				c = abs(a[i] - p);
				x = i;
			}
		}
	} else {
		x = (n / 2) + 1;
	}

	sort(a + 1, a + x);

	for (int i = x - 1; i >= 1; i--) {
		if (m == 0) {
			break;
		}
		if ((a[x] - a[i]) <= m) {
			m -= a[x] - a[i];
		}
		++ans;
	}

	for (int i = x; i <= n; i++) {
		if (a[i] == a[x]) {
			++ans;
		}
	}

	cout << ans;
	return 0;
}