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
  const int M = 5e5 + 5;
  const int N = 502;
  using ai2 = array<int, 2>;
  int w[M]; vector<ai2> l[M];
  unordered_map<int, int> dis[N];
  ll dp[N][N];
  int main() {
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
      cin >> w[i], l[i].reserve(d);
    for(int i = 1; i <= n; i++) {
      int k; cin >> k; dis[i].reserve(k);
      while(k--) {
        int a, t; cin >> a >> t;
        dis[i][a] = t, l[a].push_back({i, t});
      }
    }
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(i != j) dp[i][j] = inf;
    for(int i = 1; i <= n; i++)
      for(auto[j, t0] : dis[i])
        for(auto[k, t1] : l[j])
          dp[i][k] = min(dp[i][k], (ll)t0 + t1);
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          if(dp[i][k] + dp[k][j] < dp[i][j])
            dp[i][j] = dp[i][k] + dp[k][j];
    while(q--) {
      int x, y; cin >> x >> y;
      ll ans = 0; ans += w[x], ans += w[y];
      ll mn = inf;
      for(auto[i, tx] : l[x])
        for(auto[j, ty] : l[y])
          mn = min(mn, tx + ty + dp[i][j]);
      ans += mn;
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
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  #endif
  akitsuki :: main();
  return 0;
}
// g++ -o o subway.cpp -O2 -std=c++14 -static -DLOCAL -Wall
// 15:04 pp