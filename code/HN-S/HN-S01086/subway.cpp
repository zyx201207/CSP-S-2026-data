#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int> ;

const ll inf = 1e18;
template <typename T>
bool Chkmax(T &x, T y) { return (x < y) ? (x = y, 1) : 0; }
template <typename T>
bool Chkmin(T &x, T y) { return (x > y) ? (x = y, 1) : 0; }

const int kN = 505, kM = 5e5 + 5;
int sid, n, m, d, q;
int w[kM];
ll dis[kN][kN];
vector<pii> vec[kM];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> sid >> n >> m >> d >> q;
  for(int i = 1; i <= m; i++) cin >> w[i];
  for(int i = 1; i <= n; i++) {
    int sz;
    cin >> sz;
    vector<int> x (sz), t (sz);
    for(int j = 0; j < sz; j++) {
      cin >> x[j] >> t[j];
      vec[x[j]].emplace_back(i, t[j]);
    }
  }
  memset(dis, 0x3f, sizeof(dis));
  for(int i = 1; i <= n; i++) dis[i][i] = 0;
  for(int i = 1; i <= m; i++) {
    for(auto [p1, t1] : vec[i]) {
      for(auto [p2, t2] : vec[i]) {
        Chkmin<ll> (dis[p1][p2], t1 + t2);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 1; k <= n; k++) {
        Chkmin(dis[j][k], dis[j][i] + dis[i][k]);
      }
    }
  }
  for(int i = 1; i <= q; i++) {
    int s, t;
    cin >> s >> t;
    ll ans = inf;
    for(auto [p1, t1] : vec[s]) {
      for(auto [p2, t2] : vec[t]) {
        Chkmin(ans, t1 + t2 + dis[p1][p2]);
      }
    }
    cout << ans + w[s] + w[t] << "\n";
  }
  return 0;
}