#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long
int n, m, a[N], ans;
signed main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1, s = 0; j <= n; ++j) {
		s += (j - i) * (a[j] - a[j - 1]);
		while (s > m) s -= a[j] - a[i], ++i;
		ans = max(ans, j - i + 1);
	}
	cout << ans;
	return 0;
} 
