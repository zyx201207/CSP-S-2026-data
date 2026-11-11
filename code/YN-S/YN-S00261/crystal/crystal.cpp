#include <iostream>
#include <algorithm>
#define int long long
const int N = 500010;
int a[N], sum[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, ans = 0;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		if ((a[i] * 1LL * i - sum[i]) <= m)
			ans = i;
		else
			break;
	}
	std::cout << ans;
	return 0;
}
