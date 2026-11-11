#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, t, k, b, c;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1)
			continue;
		if (a[i] != a[i - 1]) {
			b = 1;
		}
		if (i > 2) {
			if (a[i] - a[i - 1] != a[i - 1]) {
				c = 1;
			}
		}
	}
	if (b == 0) {
		cout << n;
		return 0;
	}
	if (c == 0) {
		k = 1;
		t = m;
		for (int j = n - 1; j >= 1; j--) {
			if (a[n] - a[j] <= t) {
				k++;
				t -= a[n] - a[j];
			} else {
				break;
			}
		}
		cout << k;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		if (i <= ans)
			break;
		k = 1;
		t = m;
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] - a[j] <= t) {
				k++;
				t -= a[i] - a[j];
			} else {
				break;
			}
		}
		ans = max(ans, k);
	}
	cout << ans;
	return 0;
}
