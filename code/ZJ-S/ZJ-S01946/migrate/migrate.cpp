#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##END = (r); i <= i##END; ++ i)
#define dwn(i, l, r) for (int i = (l), i##END = (r); i >= i##END; -- i)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std; typedef long long i64;

namespace Migrate{
  const int N = 2e6 + 5;
  i64 x[N], d, g[N], ans = 0;
  int n, dp[N], z[N], lst[N];
  void main(int idx){
    cin >> n >> d;
    rep(i, 1, n) cin >> x[i];
    if (idx <= 10){
      ans = 0;
      rep(st, 1, n){
        dp[st] = 1, g[st] = 1;
        i64 sumg = 1;
        rep(i, st + 1, n) g[i] = 0, dp[i] = 1e9;
        for (int l = st, r = st, j = st + 1; j <= n; ++ j){
          if (x[j] - x[j - 1] > d) break;
          while (l < j && x[j] - x[l] > d) sumg -= g[l], ++ l;
          while (r < j && dp[r + 1] <= dp[l]) sumg += g[++ r];
          if (sumg == 2 && r - l + 1 <= 2) ++ ans;
          g[j] = sumg, dp[j] = dp[l] + 1;
        }
      }
      cout << ans << '\n';
      return ;
    } else if (idx >= 11 && idx <= 12){
      ans = 0;
      dp[1] = 1, g[1] = 1;
      i64 sumg = 1;
      rep(i, 2, n) g[i] = 0, dp[i] = 1e9, z[i] = 0;
      for (int l = 1, r = 1, j = 2; j <= n; ++ j){
        if (x[j] - x[j - 1] > d) break;
        while (l < j && x[j] - x[l] > d) sumg -= g[l], ++ l;
        while (r < j && dp[r + 1] <= dp[l]) sumg += g[++ r];
        if (sumg == 2 && r - l + 1 <= 2) z[j] = 1;
        g[j] = sumg, dp[j] = dp[l] + 1;
      }
      rep(i, 2, n) ans += z[i] * (n - i + 1);
      cout << ans << '\n';
      return ;
    } else {
      lst[1] = 1;
      for (int r = 2, l = 1; r <= n; ++ r){
        while (x[r] - x[l] > d) ++ l;
        if (l == r) lst[r] = -1e9;
        else lst[r] = l;
      }
      ans = 0;
      rep(i, 2, n){
        dp[i] = 1, g[i] = 1;
        i64 sumg = 1; int dn = max(1, (i - lst[i] > 3 ? i - 6 : 1));
        rep(j, 1, i - 1) g[j] = 0, dp[j] = 1e9;
        for (int l = i, r = i, p = i - 1; p >= dn; -- p){
          if (x[p + 1] - x[p] > d) break;
          while (l > p && x[l] - x[p] > d) sumg -= g[l], -- l;
          while (r > p && dp[r - 1] <= dp[l]) sumg += g[-- r];
          if (sumg == 2 && r - l + 1 <= 2) ++ ans;
          g[p] = sumg, dp[p] = dp[l] + 1;
        }
      }
      cout << ans << '\n';
    }
  }
}

int main(){
  File("migrate");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int id, T; cin >> id >> T;
  while (T --) Migrate::main(id);
  return 0;
}