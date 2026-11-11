#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pp pair<int, int>
#define ll long long
using namespace std;
namespace justin_jiajia {
// void clo() { cerr << (((double)clock()) / CLOCKS_PER_SEC) << '\n'; }
const int mxline = 505;
const int mxstation = 5e5 + 5;
int t_from_ground[mxstation];
int c, line_cnt, station_cnt, d, query_cnt;
vector<pp> lineinstation[mxstation];  // pair<lineID, time needed from
                                      // underground to the line>
vector<pp> stationinline[mxline];
ll transfer_between_line[mxline][mxline];
bool vis[mxline];
vector<pp> edges[mxline];
void solve() {
  memset(transfer_between_line, 0x3f, sizeof transfer_between_line);
  cin >> c >> line_cnt >> station_cnt >> d >> query_cnt;
  for (int i = 1; i <= station_cnt; i++) cin >> t_from_ground[i];
  for (int a, t, k, line = 1; line <= line_cnt; line++) {
    cin >> k;
    for (int i = 1; i <= k; i++) {
      cin >> a >> t;
      lineinstation[a].emplace_back(line, t);
      stationinline[line].emplace_back(a, t);
    }
  }
  // clo();
  // d*(sum_of_k)=2e1*5e5=1e7
  for (int line = 1; line <= line_cnt; line++) {
    for (auto p2 : stationinline[line]) {
      const int station = p2.first, t1 = p2.second;
      for (auto p : lineinstation[station]) {
        const int anotherline = p.first, t2 = p.second;
        if (anotherline == line) continue;
        transfer_between_line[line][anotherline] =
            min(transfer_between_line[line][anotherline], (ll)t1 + (ll)t2);
      }
    }
  }
  // clo();
  for (int k = 1; k <= line_cnt; k++) {
    for (int i = 1; i <= line_cnt; i++)
      if (transfer_between_line[k][i] != transfer_between_line[0][0] &&
          i != k) {
        edges[i].emplace_back(transfer_between_line[k][i], k);
      }
  }
  // clo();

  memset(transfer_between_line, 0x3f, sizeof transfer_between_line);

  priority_queue<pair<ll, int>> q;
  for (int k = 1; k <= line_cnt; k++) {
    transfer_between_line[k][k] = 0;
    q.push({0, k});
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
      auto p = q.top();
      int u = p.second;
      q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (auto p2 : edges[u]) {
        const int w = p2.first, v = p2.second;
        if (transfer_between_line[k][v] > transfer_between_line[k][u] + w) {
          transfer_between_line[k][v] = transfer_between_line[k][u] + w;
          q.push({-transfer_between_line[k][v], v});
        }
      }
    }
  }
  // n^2*logn=5e2^2*10=25e4*10=2e6
  for (int x, y, qu = 1; qu <= query_cnt; qu++) {  // d^2*q=400*1e5=4e7
    cin >> x >> y;
    ll base_time = (ll)t_from_ground[x] + (ll)t_from_ground[y];
    ll res = 1e18;
    for (auto p1 : lineinstation[x])
      for (auto p2 : lineinstation[y])
        res = min(res, base_time + p1.second + p2.second +
                           transfer_between_line[p2.first][p1.first]);
    cout << res << '\n';
  }
}
};  // namespace justin_jiajia
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  justin_jiajia::solve();
}