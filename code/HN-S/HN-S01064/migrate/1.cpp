#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 5, N = 5005;

struct node {
  int dis, c;
} dis[N][N];

ll limd, position[MAXN];
int Tid, T, n, limto[MAXN];

node Min(node u, node v) {
  if (u.dis > v.dis) swap(u, v);
  if (v.dis == u.dis) u.c = min(3, u.c + v.c);
  return u;
}

void Solve() {
  cin >> n >> limd;
  for (int i = 1; i <= n; i++) cin >> position[i];
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j <= n && position[j] - position[i] <= limd; j++);
    limto[i] = j - 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) dis[i][j] = {n, 0};
    dis[i][i] = {0, 1};
    for (int x = i; x <= n; x++) {
      node t = dis[i][x]; t.dis++;
      ans += (dis[i][x].c == 2);
      // if (x > i) assert(dis[x].c >= dis[x - 1].c);
      // cerr << dis[x].c << ' ';
      for (int y = x + 1; y <= limto[x]; y++) {
        dis[i][y] = Min(dis[i][y], t);
      }
    }
    // cerr << '\n';
  }
  // cerr << ans << ' ';
  ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int c = 0;
      for (int x = i + 1; x <= j; x++) {
        c += (dis[i][x].dis == dis[i][x - 1].dis && dis[i][x].dis + dis[x][j].dis == dis[i][j].dis && dis[i][x - 1].dis + dis[x - 1][j].dis == dis[i][j].dis);
      }
      ans += (c == 1);
      if (c == 1) {
        cerr << i << ' ' << j << ' ';
        for (int x = i + 1; x <= j; x++) {
          if (dis[i][x].dis == dis[i][x - 1].dis && dis[i][x].dis + dis[x][j].dis == dis[i][j].dis && dis[i][x - 1].dis + dis[x - 1][j].dis == dis[i][j].dis) cerr << x - 1;
        }
        cerr << '\n';
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  // freopen("migrate.in", "r", stdin);
  // freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> Tid >> T; T--; ) {
    Solve();
  }
  return 0;
}