#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##END = (r); i <= i##END; ++ i)
#define dwn(i, l, r) for (int i = (l), i##END = (r); i >= i##END; -- i)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std; typedef long long i64;

namespace Subway{
  const int N = 5e5 + 5;
  typedef pair<i64, int> PII;
  vector<PII> to[N];
  int n, m, D, q, cur;
  i64 d[505][505], w[N];

  void main(){
    cin >> n >> m >> D >> q;
    rep(i, 1, m) cin >> w[i];
    rep(i, 1, n){
      int k; cin >> k; cur = m + i;
      rep(i, 1, k){
        int x; i64 z; cin >> x >> z;
        to[x].push_back({z, cur - m});
      }
    }
    rep(i, 1, n) rep(j, 1, n)
      d[i][j] = (i == j ? 0 : 1e18);
    rep(i, 1, m){
      for (auto [w1, p1] : to[i])
        for (auto [w2, p2] : to[i])
          d[p1][p2] = min(d[p1][p2], w1 + w2);
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while (q --){
      int u, v; cin >> u >> v;
      i64 ans = 1e18;
      for (auto [w1, p1] : to[u])
        for (auto [w2, p2] : to[v])
          ans = min(ans, w[u] + w[v] + d[p1][p2] + w1 + w2);
      cout << ans << '\n';
    }
  }
}

int main(){
  File("subway");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int id; cin >> id;
  Subway::main(); return 0;
}