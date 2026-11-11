#include<bits/stdc++.h>

#define Cerr cerr <<
#define Cout cout <<
#define W << ' ' <<
#define Endl << '\n'
#define Back(chk) << " \n"[!!(chk)]

using namespace std;

namespace akitsuki {
  using ll = long long;
  const ll inf = 1e17;
  const int N = 505 + 6;
  ll a[N], dp[N][N];
  int main() {
    int c, T; cin >> c >> T;
    while(T--) {
      int n; ll d; cin >> n >> d;
      for(int i = 1; i <= n; i++)
        cin >> a[i];
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          if(abs(a[i] - a[j]) > d)
            dp[i][j] = inf;
          else
            dp[i][j] = 1;
      for(int i = 1; i <= n; i++)
        dp[i][i] = 0;
      for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
          for(int j = 1; j <= n; j++)
            if(dp[i][k] + dp[k][j] < dp[i][j])
              dp[i][j] = dp[i][k] + dp[k][j];
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          Cout dp[i][j] Back(j == n);
      ll ans = 0;
      for(int k = 2; k + 1 < n; k++) {
        int cl = 0, cr = 0;
        for(int i = 1; i < k; i++)
          if(dp[i][k] == dp[i][k + 1] && dp[i][k] != dp[i][k + 2])
            ++cl;
        for(int j = k + 1; j <= n; j++)
          if(dp[k][j] == dp[k + 1][j] && dp[k][j] != dp[k - 1][j])
            ++cr;
        Cout k W cl W cr Endl;
        ans += cl * cr;
      }
      Cout ans Endl;
    }
    return 0;
  }
}
signed main(signed argc, char*argv[]) {
  #ifdef LOCAL
  if(argc >= 3) {
    cin.tie(0) -> sync_with_stdio(0);
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
  }
  #else
  cin.tie(0) -> sync_with_stdio(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  #endif
  akitsuki :: main();
  return 0;
}
// g++ -o o migrate.cpp -O2 -std=c++14 -static -DLOCAL -Wall
// 15:04 100pts