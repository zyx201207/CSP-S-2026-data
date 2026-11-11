#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ull unsigned long long
#define REP(i, l, r)    for(int i = l;i <= r;i++)
#define DEP(i, r, l)    for(int i = r;i >= l;i--)
#define fi first
#define se second
#define pb push_back
#define pii std::pair<int, int> 


void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or ch > '9') {
    if (ch ==  '-') f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if (f)  x = -x;
  read(oth...);
}
int C;
namespace YZLK{
  const int N = 1e6 + 10;
  int M;
  int rt = 1;
  int n, k;
  std::vector<int> ve[N];
  int f[N], dp[N];


  int d[N];
  std::vector<int> p;
  void dfs2(int u, int fa) {
    d[u] = d[fa] + 1;
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs2(v, u);
    }
    return;
  }
  void get(int u, int fa) {
    p.pb(u);
    if (u == fa)  return;
    for(auto v:ve[u]) {
      if (d[v] == d[u] - 1) get(v, fa);
    }
  }

/*
------------
*/

  int L[N], R[N], idx;
  void dfs1(int u, int fa) {
    L[u] = ++idx;
    dp[u] = 0, f[u] = 0;
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs1(v, u);
      dp[u] = std::max(dp[u], dp[v] + 1);
      f[u] += f[v];
    }
    if (dp[u] >= M) f[u]++;
    R[u] = idx;
    return;
  }
  bool check(int x) {
    M = x;
    std::queue<int> q;
    for(auto t:p) {
      idx = 0;
      dfs1(t, 0);
      // std::cout << t << '\n';
      // REP(i, 1, n)  std::cout << dp[i] << ' ' << f[i] << '\n';
      if (f[t] <= M)  return 1;
      for(auto u:ve[t]) {
        REP(v, 1, n) {
          if (v == u or v == t) continue;
          int tot = f[v] + f[u];
          if (dp[u] < M)  tot++;
          if (dp[v] < M)  tot++;
          if (tot > k)  continue;
          // std::cout << "u,v:" << u << ' ' << v << '\n';
          REP(i, 1, n) {
            if ((L[u] <= L[i] and R[i] <= R[u]) or (L[v] <= L[i] and R[i] <= R[v])) {
              d[i] = 0;
            } else    d[i] = 1e18;
          }
          // REP(i, 1, n)  std::cout << d[i] << " \n"[i == n];
          q.push(u);
          q.push(v);
          while(!q.empty()) {
            int h = q.front();
            q.pop();
            for(auto b:ve[h]) {
              if (d[b] > d[h] + 1) {
                d[b] = d[h] + 1;
                q.push(b);
              }
            }
          }
          bool flag = 1;
          REP(i, 1, n) {
            if (d[i] > M) {flag = 0;break;}
          }
          // std::cout << x << ' ' << u << ' ' << v << ' ' << flag << '\n';
          if (flag) return 1;
        }
      }
    }
    return 0;
  }


/*
-------------
*/


  void solve1() {
    int len = n / 2;
    int l = 1, r = n, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      int sum = (mid - 1) * 4 + k;
      if (sum >= n / 2) ans = mid, r = mid - 1;
      else              l = mid + 1;
    }
    std::cout << ans << '\n';
    return;
  }


/*
-------------
*/



  bool dfs3(int u, int fa) {
    dp[u] = 0, f[u] = 0;
    for(auto v:ve[u]) {
      if (v == fa)  continue;
      dfs3(v, u);
      dp[u] = std::max(dp[u], dp[v] + 1);
    }
    if (dp[u] == M) {
      p.pb(u);
      return 1;
    }
    return 0;
  }
  bool chk(int x) {
    M = x;
    p.clear();
    dfs3(rt, 0);
    // std::cout << x << ":\n";
    // for(auto v:p) std::cout << v << ' ';
    // puts("");
    if (p.size() > k)  return 0;
    if (p.size() < k)  p.pb(rt);
    REP(i, 1, n)  d[i] = 1e18;
    std::queue<int> q;
    for(auto v:p) {
      d[v] = 0;
      q.push(v);
    }
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v:ve[u]) {
        if (d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
    REP(i, 1, n) {
      if (d[i] > M) return 0;
    }
    return 1;
  }

  void solve2() {
    rt = 1;
    p.clear();
    dfs2(rt, 0);
    int id = 1;
    REP(i, 1, n) {
      if (d[i] > d[id]) id = i;
    }
    dfs2(id, 0);
    REP(i, 1, n) {
      if (d[i] > d[rt]) rt = i;
    }
    get(rt, id);
    rt = p[p.size() / 2];
    int l = 1, r = n, ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if (chk(mid)) ans = mid, r = mid - 1;
      else          l = mid + 1;
    }
    std::cout << ans << '\n';
    return;
  }


  void main() {
    read(n, k);
    REP(i, 1, n)  ve[i].clear();
    REP(i, 1, n - 1) {
      int u, v;
      read(u, v);
      ve[u].pb(v);
      ve[v].pb(u);
    }
    if (n == k) return std::cout << 0 << '\n', void();
    if (13 <= C and C <= 14) {
      solve1();
      return;
    }
    if (C == 7 or C == 11 or C == 12) {
      solve2();
      return;
    }

    rt = 1;
    p.clear();
    dfs2(rt, 0);
    int id = 1;
    REP(i, 1, n) {
      if (d[i] > d[id]) id = i;
    }
    dfs2(id, 0);
    REP(i, 1, n) {
      if (d[i] > d[rt]) rt = i;
    }
    get(rt, id);
    int l = 1, r = n, ans = n;
    while(l <= r) {
      int mid = (l + r) >> 1;
      // std::cout << mid << '\n';
      if (check(mid)) ans = mid, r = mid - 1;
      else            l = mid + 1;
    }
    std::cout << ans << '\n';
    return;
  }
}

signed main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  int T = 1;
  read(C, T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}