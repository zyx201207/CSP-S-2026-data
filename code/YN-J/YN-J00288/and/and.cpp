#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, a[N], b[N], ans = 0, s[N], ma = 0;
char c[2005][32];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ma = max(a[i], ma);
	}
	if (m == 1) {
		cout << ma;
		return 0;
	} else if (n > 2000 && ma <= 4) {
		for (int i = 1; i <= n; i++) {
			b[a[i]]++;
		}
		if (b[4] >= m) {
			cout << 4;
		} else if (b[3] >= m) {
			cout << 3;
		} else if (b[3] + b[2] >= m) {
			cout << 2;
		} else if (b[2] >= m) {
			cout << 2;
		} else if (b[1] >= m) {
			cout << 1;
		} else if (b[1] + b[3] >= m) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	} else if (n > 2000 && ma >= 1024) {
		sort(a + 1, a + n + 1);
		cout << a[m];
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		while (x) {
			int cc = x % 2;
			x /= 2;
			if (cc == 0) {
				c[i][++s[i]] = '0';
			} else {
				c[i][++s[i]] = '1';
			}
		}
	}
	if (m == n) {
		long long sa = 1;
		for (int i = 1; i <= 32; i++) {
			bool f = 1, ff = 1;
			for (int j = 1; j <= n; j++) {
				if (c[i][j] == '1')
					f = 0;
				if (f == 0 && c[i][j] == '0') {
					ff = 0;
					break;
				}
			}
			if (ff = 1) {
				ans += (1 * sa);
			}
			sa *= 2;
		}
		cout << sa;
		return 0;
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				long long as = 0, sa = 1;
				for (int k = 1; k <= 30; k++) {
					if (c[i][k] == c[j][k] && c[i][k] == '1') {
						as += sa;
					}
					if (sa > a[i] || sa > a[j])
						break;
					sa *= 2;
				}
				//	cout << a[i] << " " << a[j] << " " << sa << endl;
				ans = max(ans, as);

			}
		}
		cout << ans;
		return 0;
	}
	cout << 0;



	return 0;
}
