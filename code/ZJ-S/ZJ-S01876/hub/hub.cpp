#include<bits/stdc++.h>

#define Cerr cerr <<
#define Cout cout <<
#define W << ' ' <<
#define Endl << '\n'
#define Back(chk) << " \n"[!!(chk)]

using namespace std;

namespace akitsuki {
  using ll = long long;
  const int N = 1e6 + 6;
  int n, k, dep[N], cc;
  mt19937 rng(time(0));
  vector<int> p[N], lev;
  namespace G0 {
    vector<int> e[N];
    int rt, hig[N];
    int f[N], siz[N], hson[N], top[N];
    void init(int u, int fa = 0) {
      hig[u] = 0, dep[u] = dep[fa] + 1;
      f[u] = fa, siz[u] = 1, hson[u] = 0;
      for(auto v : e[u]) {
        if(v == fa) continue;
        init(v, u), siz[u] += siz[v];
        hig[u] = max(hig[u], hig[v] + 1);
        if(siz[v] > siz[hson[u]]) hson[u] = v;
      }
      if(hig[u] == 0) lev.push_back(u);
    }
    void init1(int u) {
      p[min(hig[u], dep[u])].push_back(u);
      if(hson[f[u]] == u) top[u] = top[f[u]];
      else top[u] = u;
      for(auto v : e[u]) {
        if(v == f[u]) continue;
        init1(v);
      }
    }
  }
  int lca(int x, int y) {
    using namespace G0;
    while(top[x] != top[y]) {
      if(dep[top[x]] > dep[top[y]]) x = f[top[x]];
      else y = f[top[y]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    return x;
  }
  namespace G1 {
    vector<int> e[N];
    vector<int> v;
    int stk[N], top, d, rt, sum;
    bool flg;
    int calc0(int x, int y) {
      int res = min(dep[x] + dep[y] - dep[rt] * 2 - 1, d * 2);
      for(auto u : lev) {
        if(lca(x, u) == x) continue;
        if(lca(y, u) == y) continue;
        int dx = dep[x] - dep[rt];
        int dy = dep[y] - dep[rt];
        int du = dep[u] - dep[rt];
        res = min(res, dx + dy - 1 + (d - (du + min(dx, dy))));
      }
      return res;
    }
    int solve0() {
      int x = e[rt][0], y = e[rt][1];
      return sum - min(dep[x] + dep[y] - dep[rt] * 2 - 1, d * 2);
    }
    int calc1(int u, int x) {
      int res = min(dep[x] - dep[u] - 1, d * 2);
      for(auto y : lev) {
        int p = lca(x, y);
        if(p == x) continue;
        if(lca(u, y) == u) {
          int dx = dep[x] - dep[p];
          int dy = dep[y] - dep[p];
          int du = dep[p] - dep[u];
          res = min(res, dx + du - 1 + (d - (dy + min(dx, du))));
        }
      }
      return res;
    }
    int solve1() {
      sum = 1;
      for(auto u : v)
        for(auto x : e[u])
          sum += dep[x] - dep[u];
      int ans = sum;
      for(auto u : v)
        for(auto x : e[u])
          ans = min(ans, sum - calc1(u, x));
      return ans;
    }
    int solve() {
      if(flg) return solve1();
      if(e[rt].size() > 2) return solve1();
      int ans = solve1();
      return min(ans, solve0());
    }
  }
  bool check(int x) {
    using namespace G1;
    int m = p[x].size();
    if(m == 0) return 1;
    if(m > k) return 0;
    d = x, rt = p[x][0], flg = 0;
    for(auto u : p[x]) rt = lca(rt, u);
    stk[top = 1] = rt, v.push_back(rt);
    for(auto u : p[x]) {
      if(u == rt) {
        flg = 1;
        continue;
      }
      int pa = lca(u, stk[top]);
      while(top >= 2 && dep[stk[top]] > dep[pa])
        e[stk[top - 1]].push_back(stk[top]), --top;
      if(stk[top] != pa)
        stk[++top] = pa, v.push_back(pa);
      stk[++top] = u, v.push_back(u);
    }
    while(top >= 2)
      e[stk[top - 1]].push_back(stk[top]), --top;
    int ans = solve();
    // Cout d W rt W flg W ans Endl;
    for(auto u : v) e[u].clear();
    v.clear();
    return ans <= k;
  }
  int main() {
    dep[0] = -1;
    int T; cin >> cc >> T;
    while(T--) {
      cin >> n >> k;
      for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G0::e[u].push_back(v);
        G0::e[v].push_back(u);
      }
      int tt = (cc <= 10 ? 100 : cc <= 14 ? 20 : 5), ans = 0;
      while(tt--) {
        G0::rt = rng() % n + 1;
        G0::init(G0::rt),
        G0::init1(G0::rt);
        int l = -1, r = n;
        while(l + 1 < r) {
          int mid = (l + r) >> 1;
          if(check(mid)) r = mid;
          else l = mid; 
        }
        ans = max(ans, r);
        for(int i = 0; i <= n; i++)
          p[i].clear();
        lev.clear();
      }
      Cout ans Endl;
      for(int i = 0; i <= n; i++)
        G0::e[i].clear();
    }
    return 0;
  }
}
signed main(signed argc, char*argv[]) {
  #ifdef LOCAL
  if(argc >= 3) {
    cin.tie(0) -> sync_with_stdio(0);
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
  }
  #else
  cin.tie(0) -> sync_with_stdio(0);
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  #endif
  akitsuki :: main();
  return 0;
}
// g++ -o o hub.cpp -O2 -std=c++14 -static -DLOCAL -Wall
// 17:58