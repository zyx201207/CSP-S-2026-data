#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
#ifdef LOCAL
#define debug(x) (cerr << #x << " = " << x << '\n')
#else
#define debug(x) void(0)
#endif
typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 1e6 + 5;

int n, k;
vector<int> g[N];
vector<pair<int, int>> e;

int fa[N], dep[N], len[N], dp[N], out[N];

void dfs(int x, int D) {
  len[x] = dp[x] = out[x] = 0;
  for (auto y : g[x]) if (y != fa[x]) {
    fa[y] = x, dep[y] = dep[x] + 1;
    dfs(y, D), dp[x] += dp[y], len[x] = max(len[x], len[y] + 1);
  }
  dp[x] += (len[x] >= D);
}

int col[N];

void dfs2(int x) {
  int mx[2] = {0, 0};
  for (auto y : g[x]) if (y != fa[x]) {
    if (len[y] >= len[mx[0]]) 
      mx[1] = mx[0], mx[0] = y;
    else if (len[y] >= len[mx[1]])
      mx[1] = y;
  }
  for (auto y : g[x]) if (y != fa[x]) {
    col[y] = col[x];
    out[y] = max(out[x], len[mx[y == mx[0]]] + 1) + 1, dfs2(y);
  }
}

vector<int> h[N];

bool check(int x) {
  int ans = k + 1;
  for (auto [u, v] : e) {
    dep[u] = dep[v] = 0, fa[u] = v, fa[v] = u;
    dfs(u, x), dfs(v, x);
    out[u] = out[v] = 0;
    col[u] = u, col[v] = v;
    dfs2(u), dfs2(v);
    rep (j, 1, n) dp[j] = max(dp[j], 1);
    int mn[2] = {0, 0};
    rep (j, 1, n) if (out[j] <= x) {
      int &k = mn[col[j] == u];
      if (dp[j] < dp[k]) k = j;
    }
    if (dp[mn[0]] + dp[mn[1]] <= k) return 1;
  }
  return 0;
}

void fakemain() {
  cin >> n >> k, e.resize(n - 1);
  rep (i, 1, n) g[i].clear();
  for (auto &[u, v] : e) {
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  }
  len[0] = -1, dp[0] = k + 1;
  int lt = -1, rt = n;
  while (lt + 1 < rt) {
    int mid = lt + rt >> 1;
    if (check(mid)) rt = mid;
    else lt = mid;
  }
  cout << rt << '\n';
}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  };
  fre("hub");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1, c;
  cin >> c >> T;
  while (T --) fakemain();
  cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}