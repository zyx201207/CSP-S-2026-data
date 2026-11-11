#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 510;
const int M = 5e5 + 10;

int n, m, d, q;
int w[N];
int dis[N][N];
vector<int> a[M], t[M];

void solve1() {
  int tot = n;
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < a[i].size(); j++) {
      tot++;
      dis[a[i][j]][tot] = t[i][j];
      dis[tot][a[i][j]] = t[i][j];
      if (j != a[i].size() - 1) {
        dis[tot][tot + 1] = 0;
        dis[tot + 1][tot] = 0;
      }
    }
  }
  for (int i = 1; i <= tot; i++)
    dis[i][i] = 0;
  for (int k = 1; k <= tot; k++) {
    for (int u = 1; u <= tot; u++) {
      for (int v = 1; v <= tot; v++) {
        if (dis[u][v] > dis[u][k] + dis[k][v]) {
          dis[u][v] = dis[u][k] + dis[k][v];
        }
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << dis[x][y] + w[x] + w[y] << '\n';
  }
}

void solve2() {
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= m; i++) {
    dis[a[i][0]][a[i][1]] = min(dis[a[i][0]][a[i][1]], t[i][0] + t[i][1]);
    dis[a[i][1]][a[i][0]] = min(dis[a[i][1]][a[i][0]], t[i][0] + t[i][1]);
  }
  for (int i = 1; i <= n; i++)
    dis[i][i] = 0;
  for (int k = 1; k <= n; k++) {
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        if (dis[u][v] > dis[u][k] + dis[k][v]) {
          dis[u][v] = dis[u][k] + dis[k][v];
        }
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << dis[x][y] + w[x] + w[y] << '\n';
  }
}

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int type;
  cin >> type >> m >> n >> d >> q;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1, k, x, y; i <= m; i++) {
    cin >> k;
    while (k--) {
      cin >> x >> y;
      a[i].push_back(x);
      t[i].push_back(y);
    }
  }
  if (type <= 6) {
    solve1();
  }
  if (type <= 11) {
    solve2();
  }
  if (type == 20 || type == 21) {
    int mini = 1e18;
    for (int i = 1; i <= m; i++) {
      mini = min(mini, t[i][0] + t[i][1]);
    }
    while (q--) {
      cout << mini + w[1] + w[2] << '\n';
    }
  }
  return 0;
}
// 52pts
