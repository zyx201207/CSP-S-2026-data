#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans, cnt;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = n - 1; i >= 1; i--) {
		if (m >= a[n] - a[i]) {
			m = m - (a[n] - a[i]);
			cnt++;
		} else {
			break;
		}
	}
	ans = cnt + 1;
	for (int i = n - 1; i >= 1; i--) {
		m = m + cnt * (a[i + 1] - a[i]);
		if (cnt > 0) {
			cnt--;
		}
		for (int j = i - 1 - cnt; j >= 1; j--) {
			if (m >= a[i] - a[j]) {
				m = m - (a[i] - a[j]);
				cnt++;
			} else {
				break;
			}
		}
		ans = max(ans, cnt + 1);
	}
	cout << ans;
	return 0;
}