#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 1e6 + 1;

int Tc, T, n, k;
vector<int> e[kN], leaf;


bool out[kN], use[kN];
int Init(int lim) {
  fill_n(out + 1, n, 0), fill_n(use + 1, n, 0);
  vector<int> cur = leaf, nxt;
  for (; lim > 0; lim--) {
    for (auto x : cur)  out[x] = 1;
    for (auto x : cur) {
      int sz = 0;
      for (auto v : e[x])  sz += !out[v];
      if (sz > 1)  continue;
      for (auto v : e[x])  !out[v] && (nxt.push_back(v), 0);
    }
    cur = move(nxt), nxt.clear();
  }
  for (auto v : cur)  use[v] = 1;
  return cur.empty() ? -1 : cur[0];
}

bool exs[kN];
void Dfs0(int x, int fa) {
  int cnt = 0;
  for (auto v : e[x])
    v != fa && !out[v] && (Dfs0(v, x), cnt += exs[v]);
  if (cnt >= 2)  use[x] = 1;
  exs[x] = use[x] || cnt;
}
vector<int> V;
bool vis[kN];
void Get(int x, int fa) {
  V.push_back(x);
  for (auto v : e[x])
    v != fa && !use[v] && !out[v] && (Get(v, x), 0);
}
int Solve() {
  vector<int> cur, nxt;
  int h = 0;
  for (auto x : V) {
    int deg = 0;
    for (auto v : e[x])  deg += !use[v] && !out[v];
    if (deg == 1)  cur.push_back(x);
  }
  for (; !cur.empty();) {
    h++;
    for (auto x : cur)  vis[x] = 1;
    for (auto x : cur) {
      int sz = 0;
      for (auto v : e[x])  sz += !out[v] && !vis[v] && !use[v];
      if (sz > 1)  continue;
      for (auto v : e[x])  !out[v] && !vis[v] && !use[v] && (nxt.push_back(v), 0);
    }
    cur = move(nxt), nxt.clear();
  }
  return h;
}

bool Check(int lim) {
  int rt = Init(lim);
  if (rt == -1)  return 1;
  fill_n(exs + 1, n, 0), Dfs0(rt, 0);
  fill_n(vis + 1, n, 0);
  vector<int> rec;
  for (int i = 1; i <= n; i++) {
    if (vis[i] || out[i] || use[i])  continue;
    V.clear(), Get(i, 0);
    if (Solve() <= lim && V.size() > rec.size()) {
      for (auto x : rec)  use[x] = 1;
      rec = V;
    } else
      for (auto x : V)  use[x] = 1;
  }
  // cerr << rec.size() << '\n';
  return count(use + 1, use + n + 1, 1) <= k;
}


int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> Tc >> T; T--;) {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
      cin >> u >> v;
      e[u].push_back(v), e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
      e[i].size() == 1 && (leaf.push_back(i), 0);
    if (k < n) {
      // cout << Check(5) << '\n';
      int l = 1, r = n - 1, ans = n - 1;
      for (int mid; l <= r;) {
        mid = (l + r) / 2;
        if (Check(mid))  r = mid - 1, ans = mid;
        else  l = mid + 1;
      }
      cout << ans << '\n';
    } else  cout << "0\n";
    for (int i = 1; i <= n; i++)  e[i].clear();
    leaf.clear();
  }
  return 0;
}