# include <iostream>
# include <algorithm>
# define int long long
const int N = 5e5 + 5;
int n, m, a[N], S[N], ans = -114514;
// 注意到一个水晶一定会尽量让小水晶去凑它
// 我一定会尽量把接近它的水晶凑出它来
// 那么对于水晶 i，考虑 k~(i-1) 合并，需要 a_i - a_{i-1} + a_i - a_{i-2} + ... + a_i - a_{k}
// 一共有 i-1-k+1=i-k 颗
// (i-k) * a_i - (S[i-1]-s[k-1]) <= m
// i*ai - k*ai - S[i-1] + S[k-1] <= m
// i*ai - S[i-1] - m <= k * ai - S[k-1]
// 求最小的 k (k>=1).

// 考虑二分。
int f (int i) {
  int val = i * a[i] - S[i - 1] - m;
  int l = 1, r = i - 1, ret = i;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (mid * a[i] - S[mid - 1] >= val) {
      r = mid - 1; ret = mid;
    } else l = mid + 1;
  }
  return ret;
}
signed main () {
  freopen ("crystal.in", "r", stdin);
  freopen ("crystal.out", "w", stdout);
	std::cin.tie (0) -> sync_with_stdio (false);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
    std::cin >> a[i];
  } std::sort (a + 1, a + n + 1);
  for (int i = 1; i <= n; i ++) {
    S[i] = S[i - 1] + a[i];
    int p = f (i);
    ans = std::max (ans, i - p + 1);
  }
  std::cout << ans << '\n';
	return 0;
}
