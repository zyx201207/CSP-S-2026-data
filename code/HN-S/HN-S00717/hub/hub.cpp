#include <iostream> 
#include <vector> 

using namespace std;

void file () {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
}

const int kN = 4e3 + 5; 

int n, m, k, d;
vector<int> e[kN];
int dp[kN], f[kN][2], hig[kN], g[kN]; 
int mi;

void dfs (int u, int pa) {
  f[u][0] = f[u][1] = 0; 
  hig[u] = 0; 
  dp[u] = 0; 
  for (auto v : e[u]) {
    if (v != pa) {
      dfs(v, u);
      hig[u] = max(hig[u], hig[v] + 1); 
      if (f[v][0] + 1 > f[u][0])
        f[u][1] = f[u][0], f[u][0] = f[v][0] + 1;
      else 
        f[u][1] = max(f[u][1], f[v][0] + 1);
      dp[u] += dp[v];
    }
  }
  dp[u] += hig[u] >= d; 
}

void dfs2 (int u, int pa) {
  g[u] = max(g[pa] + 1, (f[u][0] + 1 == f[pa][0] ? f[pa][1] : f[pa][0]) + 1);
  if (g[u] <= d) mi = min(mi, max(1, dp[u])); 
  for (auto v : e[u]) {
    if (v != pa) {
      dfs2(v, u);
    }
  }
}

bool check () {
  for (int u = 1; u <= n; ++u) {
    for (auto v : e[u]) {
      if (u < v) {
        dfs(u, v);
        dfs(v, u);
        int ans = 0; 
        mi = n;
        g[u] = g[v] = 0;  
        for (auto x : e[u]) 
          if (x != v)
            dfs2(x, u);
        mi = min(mi, max(1, dp[u]));
        ans += mi;
        mi = n;
        for (auto x : e[v]) 
          if (x != u)
            dfs2(x, v);
        mi = min(mi, max(1, dp[v]));
        ans += mi;
        if (ans <= k) return 1;
      }
    }
  }
  return 0; 
}

void fakemain () {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    vector<int>().swap(e[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u); 
  }
  int L = 0, R = n - 1;
  while (L <= R) {
    int mid = (L + R) >> 1;
    d = mid;
    if (check()) 
      R = mid - 1;
    else
      L = mid + 1;
  }
  cout << L << '\n';
}

bool check2 () {
  int l1 = d + 1, r1 = l1 + k - 2; 
  int l2 = m - d + 1, r2 = l2;
  return (l2 - r1) / 2 + 1 <= d;
}

void solve2 () {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
  }
  if (k == n) {
    cout << 0 << '\n';
    return; 
  }
  m = (n - 1) / 2; 
  int L = 1, R = n - 1;
  while (L <= R) {
    d = (L + R) >> 1;
    if (check2()) 
      R = d - 1;
    else 
      L = d + 1;
  }
  cout << L << '\n';
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  int _, t;
  cin >> _ >> t;
  if (_ == 13 || _ == 14) {
    while (t--) solve2();
  }
  else {
    while (t--) fakemain();
  }
  return 0; 
}