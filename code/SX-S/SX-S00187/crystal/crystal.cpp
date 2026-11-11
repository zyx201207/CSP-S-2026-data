#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int a[n + 20];
	memset(a, 0, sizeof(a));
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		int h = 0, js = 0;
		for (int j = i ; j >= 1; j--) {
			if (h + a[i] - a[j] <= m) {
				js++;
				h += a[i] - a[j];
			} else {
				break;
			}

		}
		ans = max(ans, js);

	}
	cout << ans;
}
