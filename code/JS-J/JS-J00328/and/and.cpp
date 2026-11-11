#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

int main()
{
  freopen("and.in", "r", stdin);
  freopen("and.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) std::cin >> a[i];
  std::vector<int> dp(m + 1);
  std::sort(a.begin(), a.end());
  dp[0] = INT_MAX;
  for (int i = 1; i <= n; i ++) {
    for (int j = m; j >= 1; j --) {
      dp[j] = std::max(dp[j], dp[j - 1] & a[i]);
    }
  }
  std::cout << dp[m] << std::endl;
  return 0;
}
