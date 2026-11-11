#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010], b[500010], ans = 1, s = 1, p, q;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	p = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
	}
	for (int i = 2; i < n; i++) {
		if (b[i] == b[i - 1])
			q++;
	}
	if (q == n - 2) {
		for (int i = 1; i < n; i++) {
			p -= b[i] * s;
			if (p >= 0) {
				s++;
			} else {
				break;
			}
		}
		ans = s;
	} else {
		for (int j = 1; j <= n; j++) {
			p = m;
			s = 1;
			for (int i = j; i < n; i++) {
				p -= b[i] * s;
				if (p >= 0) {
					s++;
				} else {
					break;
				}
			}
			ans = max(ans, s);
		}
	}

	cout << ans;
	return 0;
}