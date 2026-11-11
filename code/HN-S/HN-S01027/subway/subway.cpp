#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Pii = pair <int, ll>;

const int kN = 505, kM = 5e5 + 5;

ll w[kM], dis[kN][kN], dist[kN];
vector <Pii> a[kM], e[kN];
int T, n, m, d, Q;

struct Node {
  int id;
  ll x;
  bool operator < (const Node &b) const {
    return x > b.x;
  }
};

int lt, rt;
bool vis[kN];
priority_queue <Node> q;
void Work (int st) {
  for (int i = 1; i <= n; ++i) {
    vis[i] = 0;
    dist[i] = 1e18;
  }
  dist[st] = 0;
  q.push ((Node){st, dist[st]});
  for (int cur; !q.empty (); ) {
    cur = q.top ().id; q.pop ();
    if (vis[cur]) {
      continue;
    }
    vis[cur] = 1;
    for (Pii i : e[cur]) {
      if (dist[i.first] > dist[cur] + i.second) {
        dist[i.first] = dist[cur] + i.second;
        q.push ((Node){i.first, dist[i.first]});
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    dis[st][i] = dis[i][st] = min (dis[st][i], dist[i]);
  }
}

void Solve (int x, int y) {
  ll ans = 1e18;
  for (Pii i : a[x]) {
    for (Pii j : a[y]) {
      ans = min (ans, dis[i.first][j.first] + i.second + j.second + w[x] + w[y]);
    }
  }
  cout << ans << '\n';
}

int main () {
  freopen ("subway.in", "r", stdin);
  freopen ("subway.out", "w", stdout);
  cin.tie (0)->sync_with_stdio (0);

  cin >> T >> n >> m >> d >> Q;
  for (int i = 1; i <= m; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dis[i][j] = 1e18;
  for (int i = 1, k; i <= n; ++i) {
    cin >> k;
    dis[i][i] = 0;
    for (int j = 1, x, t; j <= k; ++j) {
      cin >> x >> t;
      a[x].push_back ({i, t});
    }
  }
  
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < a[i].size (); ++j) {
      for (int k = j + 1; k < a[i].size (); ++k) {
        dis[a[i][j].first][a[i][k].first] = dis[a[i][k].first][a[i][j].first] = 
        min (dis[a[i][j].first][a[i][k].first], a[i][j].second + a[i][k].second);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (dis[i][j] != 1e18) {
        e[i].push_back ({j, dis[i][j]});
        e[j].push_back ({i, dis[i][j]});
      }
    }
  }
  for (int i = 1; i <= n; ++i) Work (i);

  for (int x, y; Q--; ) {
    cin >> x >> y;
    Solve (x, y);
  }
  return 0;
}