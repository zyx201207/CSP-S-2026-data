#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

const int N = 5e5 + 10;

int n;
int ans;

i64 m;
i64 a[N], p[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + a[i];
	}

	ans = 1;
	for (int i = 2; i <= n; ++i) {
		int l = 1, r = i - 1, mid = 0, pos = i;
		while (l <= r) {
			mid = l + r >> 1;
			i64 s = p[i] - p[mid - 1];
			if (s + m >= a[i] * (i - mid + 1)) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = std::max(ans, i - pos + 1);
	}
	std::cout << ans;

	return 0;
}