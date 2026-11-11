#include <iostream>
#include <vector>
using namespace std;
vector<int> edges[12];
int n, visited, state, fff_id, fff_val;
void dfs(int x, int w) {
  if (fff_val < w) {
    fff_val = w;
    fff_id = x;
  }
  for (auto y : edges[x])
    if ((1 << y) & state) {
      if (!((1 << y) & visited)) {
        visited |= (1 << y);
        dfs(y, w + 1);
      }
    }
}
int res;
bool check_less_than2() {
  int block = 0;
  visited = 0, res = -1e5;
  for (int i = 0; i < n; i++) {
    if ((!((1 << i) & state)) || ((1 << i) & visited)) continue;
    int lstvis = visited;
    fff_val = -1e5;
    dfs(i, 0);
    fff_val = -1e5;
    visited = lstvis;
    // cout << fff_id << endl;
    dfs(fff_id, 0);
    res = max(res, fff_val);
    block++;
  }
  return block <= 2;
}
void solve() {
  int k;
  cin >> n >> k;
  for (int a, b, i = 1; i < n; i++) {
    cin >> a >> b;
    a--, b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int ans = 1e5;
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) != k) continue;
    state = i;
    if (!check_less_than2()) continue;
    // cout << i << endl;
    ans = min(ans, res);
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int c, t;
  cin >> c >> t;
  while (t--) solve();
}