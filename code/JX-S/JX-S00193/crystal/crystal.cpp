#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 5;

i64 n, m, a[N], pre[N], ans = 0;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

  std::freopen("crystal.in", "r", stdin);
  std::freopen("crystal.out", "w", stdout);

	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];

	std::sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];

	ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m)
				r = mid - 1, res = mid;
			else
				l = mid + 1;
		}
		ans = std::max(ans, (i64) i - res + 1);
	}

	std::cout << ans << "\n";
	
	return 0;
}
