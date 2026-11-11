#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); i++)
#define of(i, a, b)	for (int i = (a); i >= (b); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
constexpr int N = 5e5 + 700, M = 700;
int n, m, d, q;
vector<pil> G[N];
ll w[N], dis[M][M];
int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int c;
  cin >> c >> n >> m >> d >> q;
  memset(dis, 0x3f, sizeof dis);
  fo(i, 1, n) dis[i][i] = 0;
  fo(i, 1, m) cin >> w[i];
  fo(i, 1, n) {
    int k;
    cin >> k;
    fo(j, 1, k) {
      int a;
      ll t;
      cin >> a >> t;
      G[a].push_back({i, t});
    }
  }
  fo(i, 1, m) {
    for (auto Pa : G[i]) {
      for (auto Pb : G[i]) {
        if (Pa.first == Pb.first)  continue;
        int u, v;
        ll w1, w2;
        tie(u, w1) = Pa, tie(v, w2) = Pb;
        dis[u][v] = min<ll>(dis[u][v], w1 + w2);
      }
    }
  }
  fo(k, 1, n) fo(i, 1, n) fo(j, 1, n) dis[i][j] = min<ll>(dis[i][j], dis[i][k] + dis[k][j]);
  fo(i, 1, q) {
    int x, y;
    cin >> x >> y;
    ll ans = 1e18;
    for (auto Pa : G[x]) for (auto Pb : G[y]) {
        int u, v;
        ll w1, w2;
        tie(u, w1) = Pa, tie(v, w2) = Pb;
        ans = min<ll>(ans, dis[u][v] + w1 + w2 + w[x] + w[y]);
      }
    cout << ans << "\n";
  }
  return 0;
}

