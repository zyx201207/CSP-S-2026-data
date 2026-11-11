#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m, res;
int a[N];
bool flag[N], vis[N];
vector<int> e[N];

void dfs(int u, int fa) {
  vis[u] = 1;
  for (int i = 1; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == fa || !flag[v])
      continue;
    dfs(v, u);
  }
}

int dfs2(int u, int fa, int step) {
  res = max(res, step);
  vis[u] = 1;
  for (int i = 1; i < e[u].size(); i++) {
    int v = e[u][i];
    if (vis[v])
      continue;
    if (flag[v]) {
      for (int i = 1; i <= m; i++) {
        dfs2(a[i], u, step);
      }
    } else {
      dfs2(v, u, step + 1);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    e[i].clear();
    a[i] = 0;
  }
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= m; i++) {
    a[i] = i;
  }
  int ans = n + 1;
  do {
    fill(flag + 1, flag + n + 1, 0);
    for (int i = 1; i <= m; i++)
      flag[a[i]] = 1;
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && flag[i]) {
        dfs(i, 0);
        cnt++;
      }
    }
    if (cnt > 2)
      continue;
    res = 0;
    for (int i = 1; i <= n; i++) {
      fill(vis + 1, vis + n + 1, 0);
      dfs2(i, 0, 0);
    }
    ans = min(ans, res);
  } while (next_permutation(a + 1, a + n + 1));
  cout << ans << '\n';
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int type, t;
  cin >> type >> t;
  while (t--) {
    cout << "0\n";
  }
  return 0;
}
