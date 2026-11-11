#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); i++)
#define of(i, a, b)	for (int i = (a); i >= (b); i++)
using namespace std;
using ll = long long;
mt19937 rnd(random_device {}());
int n, k;
namespace BruteForce {
  constexpr int N = 1005;
  vector<int> G[N];
  int vis[N], dis[N], dep1[N], dep2[N], mxdep1[N], mxdep2[N];
  void dfs(int u, int fa, int dep[], int mxdep[]) {
    mxdep[u] = dep[u];
    for (int v : G[u]) {
      if (v == fa) continue;
      dep[v] = dep[u] + 1;
      dfs(v, u, dep, mxdep);
      mxdep[u] = max<int>(mxdep[u], mxdep[v]);
    }
  }
  void main() {
    cin >> n >> k;
    fo(i, 1, n) G[i].clear();
    fo(i, 1, n - 1) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int Ans = 1e9;
    fo(TIMES, 1, 1000) {
      int S1 = rnd() % n + 1, S2 = rnd() % n + 1;
      fo(i, 1, n) vis[i] = dis[i] = dep1[i] = dep2[i] = mxdep1[i] = mxdep2[i] = 0;
      dfs(S1, 0, dep1, mxdep1);
      dfs(S2, 0, dep2, mxdep2);
      queue<int> Q;
      Q.push(S1), Q.push(S2);
      int cnt = k;
      vector<int> Targ;
      while (!Q.empty()) {
        if (cnt == 0)  break;
        int u = Q.front();
        Q.pop();
        cnt--;
        Targ.push_back(u);
        if (cnt == 0)  break;
        vector<int> nxt;
        for (int v : G[u]) {
          if (vis[v])  continue;
          nxt.push_back(v);
          vis[v] = 1;
        }
//        shuffle(nxt.begin(),nxt.end(),rnd);
        sort(nxt.begin(), nxt.end(), [&](int x, int y) -> bool {
          int v1 = mxdep1[x] < mxdep1[y], v2 = mxdep2[x] < mxdep2[y];
          if (v1 && v2)  return 1;
          else if (v1 == 0 && v2 == 0) return 0;
          return x < y;
        });
        for (int v : nxt)  Q.push(v);
      }
      while (!Q.empty()) Q.pop();
      fo(i, 1, n) dis[i] = 1e9;

      for (int u : Targ)
        Q.push(u), dis[u] = 0, vis[u] = 1;

      fo(i, 1, n) vis[i] = 0;
      int ans = 0;
      while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ans = max(ans, dis[u]);
        for (int v : G[u]) {
          if (vis[v]) continue;
          dis[v] = min(dis[v], dis[u] + 1);
          vis[v] = 1;
          Q.push(v);
        }
      }
      Ans = min<int>(Ans, ans);
    }
    cout << Ans << "\n";
  }
}
namespace subA {
  bool check(int x) {
    int m = n / 2;
    if (x >= m)  return 1;
    auto dist = [](int x, int y) {
      return abs(x - y) + 1;
    };
    int L = x, R = m - x + 1;
    fo(i, 1, m) if (dist(i, L) > x || dist(i, R) > x)  return 0;
    return 1;
  }
  void main() {
    cin >> n >> k;
    int m = n / 2;
    fo(i, 1, n - 1) {
      int u, v;
      cin >> u >> v;
    }
    if (k == n)  return cout << 0 << "\n", void();
    if (k == 1)  return cout << m + 1 << "\n", void();
    int L = 1, R = n + 1, ans = 0;
    while (L <= R) {
      int mid = (L + R + 1) / 2;
      if (check(mid)) {
        R = mid - 1, ans = mid;
      } else {
        L = mid + 1;
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int c, t;
  cin >> c >> t;
  while (t--) {
    if (c <= 8)  BruteForce::main();
    if (c == 13 || c == 14)  subA::main();
  }

  return 0;
}

