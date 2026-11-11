#include <iostream> 
#include <vector>
#define fi first
#define se second

using namespace std;
using ll = long long;

void file () {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
}

const int kN = 5e5 + 5;
const int kM = 505;
const ll infl = 1e18;

int n, m, d, q;
ll w[kN], dis[kM][kM];
vector<pair<int, ll>> line[kN];

void fakemain () {
  cin >> n >> m >> d >> q;
  for (int i = 1; i <= m; ++i) {
    cin >> w[i]; 
  }
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    while (c--) {
      int x, t;
      cin >> x >> t;
      line[x].emplace_back(i, t);
    }
  }
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= n; ++j)
      dis[i][j] = (i != j) * infl;
  for (int x = 1; x <= m; ++x) {
    for (int j = 0; j < line[x].size(); ++j) {
      for (int k = j + 1; k < line[x].size(); ++k) {
        pair<int, ll> p = line[x][j], q = line[x][k];
        dis[p.fi][q.fi] = dis[q.fi][p.fi] = min(dis[q.fi][p.fi], p.se + q.se); 
      }
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    ll ans = infl;
    for (auto a : line[x]) {
      for (auto b : line[y]) {
        ans = min(ans, a.se + b.se + dis[a.fi][b.fi]); 
      }
    }
    cout << ans + w[x] + w[y] << '\n';
  }
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  int _;
  cin >> _; 
  fakemain();
  return 0; 
}