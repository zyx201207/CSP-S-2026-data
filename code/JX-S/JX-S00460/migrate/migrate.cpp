#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e6 + 9;
int n, d, cid, a[N], rht[N], lft[N], f[N][2];
vector<int> vec[N];
int get(int l, int r, int x) {
  return upper_bound(vec[x].begin(), vec[x].end(), r) - lower_bound(vec[x].begin(), vec[x].end(), l);
}
int dec(int nxt) {
  if (cid == 12 || cid == 11) {
    int nt = rht[nxt], nnt = rht[nt];
    if (nnt != nt || nt != nxt) {
      int lt = nt - 1;
      if (nxt - lft[lt] == 1) return get(nt + 1, nnt, lt);
    }
  }
  return 0;
}
signed main() {
#ifndef LOCAL
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> cid >> tt;
  while (tt--) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i], vec[i].clear();
    a[0] = -4e18, a[n + 1] = 4e18;
    for (int i = 1; i <= n; ++i) {
      rht[i] = upper_bound(a + 1, a + n + 1, d + a[i]) - a - 1;
      lft[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
      vec[lft[i]].push_back(i);
      // cerr << lft[i] << ' ' << rht[i] << '\n';
    }
    int ans = 0;
    for (int i = n; i >= 1; --i) {
      for (int t : {0, 1}) {
        f[i][t] = 0;
        if (t) f[i][t] += get(i + 1, rht[i], i);
        else f[i][t] += get(i + 1, rht[i], i - 1);
        // for (; nxt <= rht[i]; ++nxt) {
        //   if (!t && i - 1 == lft[nxt]) ++f[i][t];
        //   if (t && i == lft[nxt]) ++f[i][t];
        // }
        int nxt = rht[i];
        if (i - lft[nxt] + 1 > 2) continue;
        if (t && i - lft[nxt] + 1 == 2) continue;
        if (i == nxt) continue;
        f[i][t] += f[nxt][t | (i - lft[nxt] + 1 == 2)];
        if ((cid == 12 || cid == 11) && (t | (i - lft[nxt] + 1 == 2)) == 0) {
          int nnxt = rht[nxt];
          if (lft[nnxt] == nxt - 1) {
            f[i][t] += f[nxt - 1][1] - get(i + 1, rht[i], i - 1);
          }
          f[i][t] -= dec(nxt);
        }
      }
      ans += f[rht[i]][0] - dec(rht[i]);
    }
    cout << ans << '\n';
  }
}