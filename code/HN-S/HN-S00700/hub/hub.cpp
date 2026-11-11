#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> v[N];

int c, T, n, k;

struct E {
  int x, y;
} e[N];

bool vis[N], dis[N];

int fa[N], f[N];

int find(int x) {
  return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

int Bfs() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    f[i] = n;
    if (vis[i]) {
      f[i] = 0;
      q.push(i);
    }
  }
  int ans = 0;
  for (; !q.empty(); q.pop()) {
    int x = q.front();
    ans = max(ans, f[x]);
    for (int nx : v[x]) {
      if (f[nx] > f[x] + 1) {
        f[nx] = f[x] + 1;
        q.push(nx);
      }
    }
  }
  return ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    v[i].clear();
  }
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y), v[y].push_back(x);
    e[i] = {x, y};
  }
  if (c <= 3) {
    int ans = n + 5;
    for (int s = 0; s < (1 << n); s++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        fa[i] = i;
        vis[i] = dis[i] = 0;
        if ((s >> (i - 1)) & 1) {
          cnt++;
          vis[i] = 1;
        }
      }
      if (cnt != k) {
        continue;
      }
      for (int i = 1; i < n; i++) {
        int x = e[i].x, y = e[i].y;
        if (vis[x] && vis[y]) {
          x = find(x), y = find(y);
          fa[x] = y;
        }
      }
      int o = 0;
      for (int i = 1; i <= n; i++) {
        if (vis[i]) {
          dis[find(i)] = 1;
        } 
      }
      for (int i = 1; i <= n; i++) {
        o += dis[i];
      }
      if (o > 2) {
        continue;
      }
      ans = min(ans, Bfs());
    }
    cout << ans << "\n";
    return;
  }
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> c >> T;
  for (; T--; solve()) {
  }
  return 0;
}