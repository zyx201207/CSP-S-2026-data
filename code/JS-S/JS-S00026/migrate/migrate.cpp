#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  i64 n, d;
  std::cin >> n >> d;
  std::vector<i64> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n + 1, INT_MAX / 2));
  std::vector<std::vector<i64>> minx(n + 1, std::vector<i64>(n + 1, 0));
  for (int i = 1; i <= n; i ++) {
    for (int j = i + 1; j <= n; j ++) {
      if (a[j] - a[i] > d) break;
      dp[i][j] = 1;
      minx[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 2; j <= n; j++) {
      for (int k = i + 1; k < j; k++) {
        if (dp[i][k] + dp[k][j] == dp[i][j]) {
          minx[i][j] ++;
        }
        if (dp[i][k] + dp[k][j] < dp[i][j]){
          dp[i][j] = dp[i][k] + dp[k][j];
          minx[i][j] = 1;
        }
      }
      if (minx[i][j] == 2) ans ++;
    }
  }
  // for (int len = 2; len <= n - 1; len ++) {
  //   for (int i = 1; i <= n - len; i ++) {
  //     int j = i + len;
  //     for (int k = i + 1; k < j; k ++) {
  //       if (dp[i][k] + dp[k][j] == dp[i][j]) {
  //         minx[i][j] ++;
  //       }
  //       if (dp[i][k] + dp[k][j] < dp[i][j]) {
  //         dp[i][j] = dp[i][k] + dp[k][j];
  //         minx[i][j] = 1;
  //       }
  //     }
  //     if (minx[i][j] == 2) ans ++;
  //   }
  // }
  std::cout << ans << std::endl;
}

int main() {
  // freopen("output", "w", stdout);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int c, t;
  std::cin >> c >> t;
  while (t--) solve();
  return 0;
}