/*
给定 n 个数和 m
每次可以将一个数 + 1，进行最多 m 次
求最多可以使得多少个数字重复
容易发现一定有至少一个最多重复的元素没有被加 1
否则我们让所有重复元素都减去 1 一定不劣
所以可以枚举 i 表示让尽量多的数变成 a_i
显然让 <= a_i 且最接近的数字变过去一定更优
注意这里范围可以达到 1e12 * 5e5 所有要用 long long
先进行排序，然后计算前缀和，然后对于每个元素二分位置
使得满足条件，最后取最大值就是答案
考虑到要读入 5e5 个数字，使用 IOS
100
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5 + 5;
int n, m, a[N], ans = 1, s[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (mid * a[i] - (s[i] - s[i - mid]) <= m)
				l = mid;
			else r = mid - 1;
		}
		ans = max(ans, l);
	}
	cout << ans;
	return 0;
}