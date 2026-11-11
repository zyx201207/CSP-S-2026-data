#include <bits/stdc++.h>

using i64 = long long;

namespace Qwarth {

const int N = 500007;

i64 n, m;
i64 a[N], s[N];

void main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int lo = 1, hi = i - 1, f = 0;
		while (lo <= hi) {
			int mi = (lo + hi) >> 1;
			if (a[i] * (i - mi) - (s[i - 1] - s[mi - 1]) <= m) {
				f = mi;
				hi = mi - 1;
			} else {
				lo = mi + 1;
			}
		}
		ans = std::max(ans, i - f + 1);
	}
	std::cout << ans << '\n';
}
}  // namespace Qwarth

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int _T = 1;
//	std::cin >> _T;
	while (_T--) {
		Qwarth::main();
	}
	return 0;
}
