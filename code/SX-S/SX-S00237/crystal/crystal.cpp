//总结：
//今年我什么都不求，我只求s难度严格单调递增
//有分就行，暴力打满
//Chinese Can Fly
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5+5;
constexpr int M = 1e18+5;
constexpr int A = 1e12+5;
int n, m, a[N], s[N], ans = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

//	freopen("crystal1.in", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
		int l = 1, r = i, cnt = 0; //左端点，右端点，最多a相等个数
		while (l <= r) {
			int mid = (l + r) >> 1;
			int len = i - mid + 1;
			if (len * a[i] - (s[i] - s[mid - 1]) <= m)
				cnt = len, r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}