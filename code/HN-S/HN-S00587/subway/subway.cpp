#include <fstream>
#include <vector>

using namespace std;
using LL = long long;

const LL kMaxN = 505, kMaxM = 5e5 + 5;

ifstream cin("subway.in");
ofstream cout("subway.out");

LL w[kMaxM], e[kMaxN][kMaxN], c, n, m, d, q;
vector<pair<LL, LL>> line[kMaxN], gap[kMaxM];

int main() {
  cin >> c >> n >> m >> d >> q;
  for (LL i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (LL i = 1, k; i <= n; i++) {
    cin >> k;
    line[i].resize(k);
    for (auto &j : line[i]) {
      cin >> j.first >> j.second;  // (id, time)
      gap[j.first].emplace_back(i, j.second);
    }
  }
  fill(e[0], e[0] + kMaxN * kMaxN, 1e18);
  for (LL i = 1; i <= n; i++) {
    e[i][i] = 0;
  }
  for (LL i = 1; i <= n; i++) {
    for (auto j : line[i]) {
      for (auto k : gap[j.first]) {
        e[i][k.first] = min(e[i][k.first], j.second + k.second);
      }
    }
  }
  for (LL k = 1; k <= n; k++) {
    for (LL i = 1; i <= n; i++) {
      for (LL j = 1; j <= n; j++) {
        e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }
  for (LL x, y; q; q--) {
    cin >> x >> y;
    LL ans = 1e18;
    for (auto i : gap[x]) {
      for (auto j : gap[y]) {
        ans = min(ans, w[x] + w[y] + i.second + j.second + e[i.first][j.first]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}