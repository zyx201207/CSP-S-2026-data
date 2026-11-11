#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N], ans;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
	} else if (m == 1) {
		sort (a + 1, a + n + 1, greater<int>());
		cout << a[1];
	}
	cout << ans;
	return 0;
}