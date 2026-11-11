#include <bits/stdc++.h>
using namespace std;

namespace solve1 {
  const int MAXN = 1000;
  int x[MAXN];
  int cnt[MAXN];
  int n, d;

  void dfs(int idx, int target, int dist) {
    if (idx == target) { cnt[dist]++; return ; }
    for (int j = idx + 1; j <= target; j++) if (x[j] - x[idx] <= d) dfs(j, target, dist + 1);
  }

  void solve() {
    int T; cin >> T;
    while (T--) {
      cin >> n >> d;
      for (int i = 1; i <= n; i++) cin >> x[i];
      int ans = 0;
      for (int i = 1; i <= n - 3; i++) {
        for (int j = i + 3; j <= n; j++) {
          memset(cnt, 0, sizeof cnt);
          dfs(i, j, 0);
          bool ok = false;
          for (int i = 2; i <= n; i++) if (cnt[i] == 2) { ok = true; break; }
          if (cnt[1]) ok = false;
          ans += ok;
        }
      }
      cout << ans << '\n';
    }
  }
}

namespace solve2 {
  void solve() {
    int T; cin >> T;
    while (T--) {
      int n, d; cin >> n >> d;
      vector<int> x(n + 1);
      for (int i = 1; i <= n; i++) cin >> x[i];
      if (x[3] - x[1] <= d && x[4] - x[1] > d) cout << n - 3;
      else cout << 0;
      cout << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);

  int c; cin >> c;
  // solve1::solve();
  if (1 <= c && c <= 6) {
    solve1::solve();                // solve1 -> 1~6
  } else if (11 <= c && c <= 12) {
    solve2::solve();                // solve2 -> 11~12
  }
  return 0;
}
