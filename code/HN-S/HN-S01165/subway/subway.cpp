#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 500 + 1, kM = 5e5 + 1;

int Tc, n, m, d, q;
int w[kM];
vector<PII> vec[kM];
LL dis[kN][kN];

int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> Tc >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++)  cin >> w[i];
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 1, k; i <= n; i++) {
    cin >> k;
    for (int a, t; k--;)
      cin >> a >> t, vec[a].emplace_back(i, t);
    dis[i][i] = 0;
  }
  for (int x = 1; x <= m; x++) {
    for (int i = 0; i < vec[x].size(); i++)
      for (int j = i + 1; j < vec[x].size(); j++) {
        int u = vec[x][i].first, v = vec[x][j].first;
        dis[u][v] = dis[v][u] = min(dis[u][v], 0ll + vec[x][i].second + vec[x][j].second);
      }
  }
  for (int mid = 1; mid <= n; mid++) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][mid] + dis[mid][j]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)  assert(dis[i][j] <= 1e12);
  for (int x, y; q--;) {
    cin >> x >> y;
    LL ans = 1e18;
    for (int i = 0; i < vec[x].size(); i++)
      for (int j = 0; j < vec[y].size(); j++) {
        ans = min(ans, dis[vec[x][i].first][vec[y][j].first] + vec[x][i].second + vec[y][j].second);
      }
    assert(ans <= 2e12);
    cout << ans + w[x] + w[y] << '\n';
  }
  return 0;
}