// migrate
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

const int N = 3e3 + 3;

const ll INF = 1e18;

ll x[N], dp[N][N], l[N][N];

int c, t, n;

ll d, ans;

void Solve_0() {
  cin >> n >> d, ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = INF, l[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
    for (int j = i + 1; j <= n; j++) {
      if (x[j] - x[i] <= d) dp[i][j] = 1, l[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = i + 1; k < j; k++) {
        if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j], l[i][j] = 0;
        if (dp[i][j] == dp[i][k] + dp[k][j]) l[i][j] += min(l[i][k] * l[k][j], 4ll);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans += (l[i][j] == 2);
    }
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> c >> t;
  while (t--) {
    Solve_0();
  }
  return 0;
}
