#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200010], x = pow(2, 29), ans, op = 0;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	while (x > a[n]) {
		x /= 2;
	}
	while (x >= 2) {
		int cnt = 0;
		for (int i = n; i >= 1; i--) {
			if (x > a[i])
				break;
			if ((a[n] / x) % 2 == 1) {
				cnt++;
			}
			if (cnt == m) {
				op = m;
				break;
			}
		}
		if (op != 0) {
			break;
		}
		x /= 2;
	}
	for (int i = n; i >= 1; i--) {
		if ((a[i] / x) % 2 == 1) {
			if (ans == 0) {
				ans = a[i];
			}
			ans &= a[i];
			op--;
		}
		if (op == 0) {
			break;
		}
	}
	cout << ans;
	return 0;
}