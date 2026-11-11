#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int b[500010];
int h[500010];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (h[i] != i) {
			ok = false;
		}
	}
	if (ok = true) {
		int a = m;
		for (int i = 1; i <= n; i++) {
			a += h[i];
		}
		int s = 0;
		for (int i = 1; i <= n; i++) {
			if (h[i] < a / n) {
				s++;
			}
		}
		cout << s;
	} else {
		for (int i = 1; i <= n; i++) {
			a[i] = h[i];
		}
		int mx = 1;
		for (int i = 2; i <= n; i++) {
			if (m == 0) {
				break;
			}
			if (a[i - 1] < a[i]) {
				for (int j = 1; j < i; j++) {
					m = m - (a[i] - a[j]);
					a[j] = a[i];
				}
			}
		}
		int s = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i] != a[i - 1]) {
				mx = max(mx, s);
				s = 1;
			} else {
				s++;
			}
		}
		cout << mx;
	}

	return 0;
}