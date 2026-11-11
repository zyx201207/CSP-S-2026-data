#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = -1;
	if (m == 1) {
		for (int i = 1; i <= n; i++) ans = max(ans, (a[i] & a[i]));
	}
	if (m == 2) {
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) ans = max(ans, (a[i] & a[j]));
		}
	}
	cout << ans;
	return 0;
}
