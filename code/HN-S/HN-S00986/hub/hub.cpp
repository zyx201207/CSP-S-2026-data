#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define int long long
#define chkmax(x, y) (x = max(x, y))
#define chkmin(x, y) (x = min(x, y))
#define pb push_back
using namespace std;

const int MAXN = 2e6 + 5;

int c, T, n, k;
vector<int> e[MAXN];

int cnt;
bool vis[MAXN], col[MAXN];
void dfs(int u) {
  vis[u] = 1;
  if (!col[u]) return;
  for (int v : e[u]) {
    if (vis[v]) continue;
    dfs(v);
  }
}
int dis[MAXN];
void bfs() {
  rep(i, 1, n) dis[i] = n + 1;
  queue<int> q;
  rep(i, 1, n) if (col[i]) dis[i] = 0, q.push(i);
  for (;q.size(); q.pop()) {
    int u = q.front();
    for (int v : e[u]) {
      if (dis[v] == n + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
}

void solve() {
  cin >> n >> k;
  rep(i, 1, n) e[i].clear();
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    e[u].pb(v), e[v].pb(u);
  }
  int ans = n + 1;
  rep(S, 0, (1 << n) - 1) {
    int c = 0;
    rep(i, 1, n) if (S >> (i - 1) & 1) c++;
    if (c == k) {
      rep(i, 1, n) vis[i] = 0, col[i] = S >> (i - 1) & 1;
      cnt = 0;
      rep(i, 1, n) {
        if (!vis[i]) {
          dfs(i), cnt += col[i];
        }
      }
      if (cnt <= 2) {
        bfs();
        int mx = 0;
        rep(i, 1, n) chkmax(mx, dis[i]);
        chkmin(ans, mx);
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> c >> T; T--; solve());
  return 0; 
}
// g++ hub.cpp -o hub -std=c++14 && ./hub