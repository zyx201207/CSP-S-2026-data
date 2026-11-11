#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++) {
		int x = 1, nm = m;
		for (int j = i + 1; j <= n; j++) {
			if (a[i] - nm <= a[j]) {
				x++;
				nm -= (a[i] - a[j]);
			} else
				break;
		}
		ans = max(ans, x);
	}
	cout << ans;
	return 0;
}