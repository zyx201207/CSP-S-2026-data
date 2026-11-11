#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], c[500005], cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[i] = a[i] - a[i - 1];
	}
	for (int i = 2; i <= n; i++) {
		if (i == 2) {
			if (c[i] <= m) {
				cnt += 2;
				m -= c[i];
			} else {
				break;
			}
		} else {
			if (c[i] + c[i] <= m) {
				cnt++;
				m -= (c[i] + c[i]);
			} else {
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}