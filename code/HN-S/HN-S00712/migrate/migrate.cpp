#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 10, INF = 1e9;

ll n, d, a[MAXN], dp[MAXN], cnt[MAXN], pre[MAXN];

void Solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; cin >> a[i++]);
  ll ans = 0;
  for (int u = 1; u <= n; u++) {
    fill(dp + 1, dp + n + 1, -INF);
    dp[u] = 0, cnt[u] = pre[u] = 1, pre[u - 1] = 0;
    for (int v = u + 1; v <= n; v++) {
      int l = max((ll)u, lower_bound(a + 1, a + n + 1, a[v] - d) - a);
      if (l == v) continue;
      int r = upper_bound(dp + u, dp + v, dp[l]) - dp - 1;
      dp[v] = dp[l] + 1, cnt[v] = pre[r] - pre[l - 1], pre[v] = pre[v - 1] + cnt[v];
      ans += cnt[v] == 2;
    }
  }
  cout << ans << '\n';
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  for (cin >> c >> T; T--; Solve());
  return 0;
}
