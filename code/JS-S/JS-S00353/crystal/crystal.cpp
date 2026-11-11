#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[500005], ans = 0;

signed main() {
// #ifndef MY_JUDGE
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
// #endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l, r;
	for (l = r = 1; r <= n; r++) {
		m -= (a[r] - a[r - 1]) * (r - l);
		while(m < 0) m += a[r] - a[l++];
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}