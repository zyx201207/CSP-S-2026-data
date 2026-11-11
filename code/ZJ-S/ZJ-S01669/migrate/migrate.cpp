#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ull unsigned long long
#define REP(i, l, r)    for(int i = l;i <= r;i++)
#define DEP(i, r, l)    for(int i = r;i >= l;i--)
#define fi first
#define se second
#define pb push_back
#define pii std::pair<int, int> 


void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or ch > '9') {
    if (ch ==  '-') f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if (f)  x = -x;
  read(oth...);
}
int C;
namespace YZLK{
  const int N = 2e6 + 10;
  int n, d;
  int a[N];
  pii dp[N];
  int s[N];
  void main() {
    read(n, d);
    REP(i, 1, n)  read(a[i]);
    if (C <= 10) {
      int cnt = 0;
      REP(i, 1, n) {
        dp[i] = {0, 1};
        s[i - 1] = 0;
        s[i] = 1;
        int l = i, r = i;
        REP(j, i + 1, n) {
          if (a[j] - a[j - 1] > d)  break;
          while(l < j - 1 and a[j] - a[l] > d)  l++;
          r = l;
          while(r < j - 1 and dp[r + 1].fi == dp[l].fi) r++;
          dp[j] = {dp[l].fi + 1, s[r] - s[l - 1]};
          // std::cout << i << ' ' << j << ' ' << l << ' ' << r << ' ' << dp[j].fi << ' ' << dp[j].se << '\n';
          if (dp[j].se == 2)  cnt++;
          s[j] = s[j - 1] + dp[j].se;
        }
        // REP(j, i + 1, n)  std::cout << dp[i].fi << ' ' << dp[i].se << '\n';
        // puts("");
      }
      std::cout << cnt << '\n';
      return;
    }
    // if (11 <= C and C <= 12) {
    //   int k = a[2] - a[1], c = d / k;
    //   if (c == 0) return std::cout << 0 << '\n', void();
    //   int cnt = 0;
    //   REP(i, 1, n) {
    //     int tot = (n - i) / k;
        
    //   }
    //   std::cout << cnt << '\n';
    //   return;
    // }
    return;
  }
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int T = 1;
  read(C, T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}