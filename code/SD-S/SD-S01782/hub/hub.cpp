#include <bits/stdc++.h>

namespace silvecor {
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
template <typename T>
using vec = std::vector<T>;
using std::pair;
using str = std::string;
template <typename T>
bool chmin(T &x, T y) { return y < x ? (x = y, true) : false; }
template <typename T>
bool chmax(T &x, T y) { return y > x ? (x = y, true) : false; }

static constexpr int N = 1e6 + 10;

int n, k, siz[N], dep[N], mxDep[N], id[N];
vec<int> g[N];
int rt, rtSz;
int rt1, rt2;

void clearPrv() {
  for (int i = 1; i <= n + 5; ++i) {
    g[i].clear();
    siz[i] = 1;
    dep[i] = 0;
    mxDep[i] = 0;
  }
  rt = 0;
}
void dfs(int u, int fa) {
  int curSiz = 0;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    chmax(curSiz, siz[v]);
    siz[u] += siz[v];
  }
  chmax(curSiz, n - siz[u]);
  if (rt == 0 or rtSz > curSiz) {
    rtSz = curSiz;
    rt = u;
  }
}

void dfs2(int u, int fa, int &mx) {
  dep[u] = dep[fa] + 1;
  chmax(mx, dep[u]);
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs2(v, u, mx);
    siz[u] += siz[v];
  }
}

int ans = 1e8;

void dfs3(int u, int fa, int &r) {
  int curSiz = 0;
  for (int v : g[u]) {
    if (v == fa or v == rt or v == n + 1) continue;
    dfs3(v, u, r);
    chmax(curSiz, siz[v]);
    siz[u] += siz[v];
  }
  chmax(curSiz, n - siz[u]);
  if (r == 0 or rtSz > curSiz) {
    rtSz = curSiz;
    r = u;
  }
}

void innerSolve() {
  std::cin >> n >> k;
  clearPrv();
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u); 
  }
  if (n == k or n == 1) {
    std::cout << "0\n";
    return; 
  }
  if (n == 2) {
    if (k == 1) std::cout << "1\n";
    else std::cout << "0\n";
    return; 
  }
  dfs(1, 0);
  // rt=centroid
  // delete rt, select the biggest ch
  for (int i = 1; i <= n; ++i) {
    siz[i] = 1;
  }
  for (int ch : g[rt]) {
    dfs2(ch, rt, mxDep[ch]); 
  }
  
  for (int i = 1; i <= n; ++i) {
    id[i] = i; 
  }
  std::sort(id + 1, id + n + 1, [&](int x, int y) { return mxDep[x] > mxDep[y]; });
  
  // id[1], id[2];
  // dep3 : 
  
//  g[id[1]].push_back(n + 1);
//  g[id[2]].push_back(n + 1);
////  siz[n + 1] = mxDep[id[3]] + 1;
//  siz[n + 1] = n - siz[id[1]] - siz[id[0]];
//  dep[n + 1] = mxDep[id[3]] + 1;
//  
//  for (int i = 1; i <= n; ++i) {
//    siz[i] = 1;
//  }
//  
//  rt1 = 0, rt2 = 0;
//  dfs3(id[1], rt1);
//  dfs3(id[2], rt2);
  
  std::cout << mxDep[id[3]] + 1 << '\n';
}
void solve() {
  int _no, t;
  std::cin >> _no >> t;
  while (t--) innerSolve();
}
}

int main() {
#ifndef LOCAL_DBG
  std::freopen("hub.in", "r", stdin);
  std::freopen("hub.out", "w", stdout); 
#endif
  std::cin.tie(nullptr)->sync_with_stdio(false);
  silvecor::solve();
  return 0;
}
