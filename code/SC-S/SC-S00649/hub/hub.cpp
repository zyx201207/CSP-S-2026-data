#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> edge(n - 1);
  for (auto &[u, v] : edge) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }

  auto solve = [&](int rt, int fa) {
    vector<int> siz(n + 1, 1);
    vector<int> ans(k + 1, 1e9), len(n + 1), dfn(n + 1), dep(n + 1);
    vector<pair<int, int>> mx1(n + 1), mx2(n + 1);
    int timer = 0;
    auto dfs1 = [&](auto &&self, int u, int fa) -> void {
      dfn[u] = ++timer;
      for (int v : g[u]) if (v != fa) {
        dep[v] = dep[u] + 1, self(self, v, u);
        if (len[v] + 1 >= mx1[u].first) mx2[u] = mx1[u], mx1[u] = {len[v] + 1, mx1[v].second};
        else if (len[v] + 1 >= mx2[u].first) mx2[u] = {len[v] + 1, mx1[v].second};
        len[u] = max(len[u], len[v] + 1);
      }
      if (mx1[u].second == 0) mx1[u].second = u;
    }; dfs1(dfs1, rt, fa);

    // cerr << rt << ' ' << fa << endl;
    // for (int i = 1; i <= n; i++) {
    //   cerr << "i : " << i << endl;
    //   cerr << mx1[i].first << ' ' << mx1[i].second << endl;
    //   cerr << mx2[i].first << ' ' << mx2[i].second << endl;
    //   cerr << dep[i] << ' ' << len[i] << endl << endl;
    // }
    // cerr << "------------" << endl;

    int pos = mx1[rt].second;

    auto dfs = [&](auto &&self, int u, int fa) -> vector<int> {
      vector<int> dp(2);
      for (int v : g[u]) if (v != fa) {
        vector<int> f(min(k + 1, siz[u] + siz[v] + 1), 1e9);
        auto g = self(self, v, u);
        for (int i = 1; i <= siz[u]; i++)
          for (int j = 0; j <= min(k - i, siz[v]); j++) if (i + j <= min(k, siz[u] + siz[v]))
            f[i + j] = min(f[i + j], max(dp[i], g[j]));
        swap(f, dp);
        siz[u] += siz[v];
      }
      dp[0] = len[u] + 1;
      if (siz[u] <= k) dp[siz[u]] = 0; 
      for (int i = 1; i <= min(k, siz[u]); i++) {
        int len = mx1[rt].first;
        if (dfn[u] <= dfn[pos] && dfn[pos] <= dfn[u] + siz[u] - 1)
          len = mx2[rt].first;
        len += dep[u] - dep[rt];
        //if (i == k - 1) cerr << u << ' ' << dp[i] << ' ' << len << endl;
        //cerr << u << ' ' << i << ' ' << len + dp[i] << endl;
        ans[i] = min(ans[i], max(len, dp[i]));
      }

      // cerr << u << endl;
      // for (int i = 0; i <= min(k, siz[u]); i++) cerr << dp[i] << ' ';
      // cerr << endl;
      // for (int i = 0; i <= k; i++) cerr << ans[i] << ' ';
      // cerr << endl;

      return dp;
    };
    
    auto dp = dfs(dfs, rt, fa);

    for (int i = 1; i <= min(k, siz[rt]); i++) ans[i] = min(ans[i], dp[i]);

    return ans;
  };

  auto cur = solve(1, 0);

  int ans = cur[k];
  for (auto [u, v] : edge) {
    auto res1 = solve(u, v);
    auto res2 = solve(v, u);
    for (int i = 1; i < k; i++) ans = min(ans, max(res1[i], res2[k - i]));
  }

  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
  int c, T; cin >> c >> T; while (T--) solve();
  return 0;
}