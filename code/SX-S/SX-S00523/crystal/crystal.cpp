#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt = 0, ans, m1, k;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		cnt = 0;
		k = i;
		m = m1;
		while (m > 0 && k > 0) {
			k--;
			if (m >= (a[i] - a[k])) {
				m -= (a[i] - a[k]);
				cnt++;
			} else
				m = 0;
		}
		ans = max(ans, cnt);

	}
	cout << ans;
	return 0;
}