#include <bits/stdc++.h>
using namespace std;
long long n, m, b, c;
long long a[500005];
int ans, ans1 = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			ans1++;
		} else {
			if (ans1 > ans) {
				ans = ans1;
				b = a[i - 1];
				c = i - 1;
			}
			ans1 = 1;
		}
	}
	for (int i = c; i >= 1; i--) {
		if (a[i] < b && m >= (b - a[i])) {
			m -= (b - a[i]);
			ans++;
		}
	}
	while (m) {
		if (m >= (ans * (a[c + 1] - b)) && c + 1 <= n) {
			m -= (ans*(a[c + 1] - b));
			ans++;
			c++;
			b = a[c + 1];
		} else {
			break;
		}
	}
	cout << ans;
	return 0;
}
