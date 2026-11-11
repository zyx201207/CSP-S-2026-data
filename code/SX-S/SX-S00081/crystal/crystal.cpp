#include <bits/stdc++.h>
using namespace std;
long long n, m, tong[500005], sum, maxx, q, ans;
bool x, y;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> tong[i];
		if (tong[i] != i) {
			x = 1;
		}
		if (i == 2) {
			q = tong[i] - tong[i - 1];
		} else if (i > 2) {
			if (q != tong[i] - tong[i - 1]) {
				y = 1;
			}
		}
	}
	if (x == 0) {
		for (int i = 1; i <= n; i++) {
			if ((1 + i) * i / 2 > m) {
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	if (y == 0) {
		for (int i = 1; i <= n; i++) {
			if (m >= i * q) {
				m -= (i *q);
				ans++;
			} else {
				cout << ans + 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	sort(tong + 1, tong + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum = 1;
		long long p = m, jj = i - 1;
		while (jj) {
			if (p >= (tong[i] - tong[jj])) {
				p -= (tong[i] - tong[jj]);
				jj--;
				sum++;
			} else {
				break;
			}
		}
		maxx = max(maxx, sum);
	}
	cout << maxx;
	return 0;
}