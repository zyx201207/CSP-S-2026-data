#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
const int inf = 1e18;

void solve() {
	int n, d, D, ans = 0;
	std::cin >> n >> d;
	std::vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (i > 1)
			D = a[i] - a[i - 1];
	}
	int jump = std::min(d / D, n);
	if (jump == 1) {
		std::cout << 0 << "\n";
		return;
	}
	for (int i = 1; i <= n - jump * 2 + 1; i++) {
		ans++;
	}
	std::cout << ans << "\n";
}

void solve2() {
	int n, d, mid, ans = 0;
	std::cin >> n >> d;
	std::vector<int>a(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (llabs(a[i] - a[1]) <= d && llabs(a[i] - a[n]) <= d) {
			mid = i;
			break;
		}
	}
	int j = mid ;
	for (int i = 1; i < mid; i++) {
		while (llabs(a[i] - a[j]) <= d && j <= n)
			j++;
		if (j - mid == 1)
			ans++;
	}
	j = mid ;
	for (int i = n; i > mid; i--) {
		while (llabs(a[i] - a[j]) <= d && j > 0)
			j--;
		if (j - mid == 1)
			ans++;
	}
	std::cout << ans << "\n";
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	std::cin >> c >> T;
	while (T--) {
		if (c == 11 || c == 12)
			solve();
		else
			solve2();
	}

	return 0;
}
