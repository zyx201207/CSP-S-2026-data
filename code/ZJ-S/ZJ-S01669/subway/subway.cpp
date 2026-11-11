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

namespace YZLK{
  const int N = 5e2 + 10;
  const int M = 5e5 + 10;
  int c, n, m, d, q;
  int w[M];
  int f[N][N];
  std::vector<pii> ve[M];
  void main() {
    read(c, n, m, d, q);
    REP(i, 1, m)  read(w[i]);
    memset(f, 0x3f, sizeof(f));
    REP(i, 1, n) {
      int k, a, t;
      read(k);
      REP(j, 1, k) {
        read(a, t);
        ve[a].pb({i, t});
      }
    }
    REP(i, 1, m) {
      for(auto [u, w1]:ve[i]) {
        for(auto [v, w2]:ve[i]) {
          if (u == v) continue;
          f[u][v] = std::min(f[u][v], w1 + w2);
          f[v][u] = std::min(f[v][u], w1 + w2);
        }
      }
    }
    REP(i, 1, n)  f[i][i] = 0;
    REP(k, 1, n) {
      REP(i, 1, n) {
        if (i == k) continue;
        REP(j, 1, n) {
          if (i == j or j == k) continue;
          f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
        }
      }
    }
    while(q--) {
      int x, y;
      read(x, y);
      int ans = 1e18;
      for(auto [u, w1]:ve[x]) {
        for(auto [v, w2]:ve[y]) {
          ans = std::min(ans, w1 + w2 + w[x] + w[y] + f[u][v]);
        }
      }
      std::cout << ans << '\n';
    }
    return;
  }
}

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}