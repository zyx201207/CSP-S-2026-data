// 我 TM 的自动格式化。
// 怎么 T1 WA 了？（__int128）
// 我愚笨，双指针即可。

#include <bits/stdc++.h>
#define int long long

using namespace std;

constexpr int N = 5e5 + 10;
int n, M, ans, a[N];

auto main() -> signed {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> M;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	sort(a + 1, a + n + 1);

	ans = 1; __int128 m = M;
	for (int i = 2, j = 1; i <= n; i ++) {
		m -= __int128(1) * (i - j) * (a[i] - a[i - 1]);

		for (; m < 0; j ++) m += (a[i] - a[j]);
		ans = max(ans, i - j + 1);
	}

	cout << ans << '\n';

	return 0;
}