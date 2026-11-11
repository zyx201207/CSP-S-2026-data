#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define int long long
#define chkmax(x, y) (x = max(x, y))
#define chkmin(x, y) (x = min(x, y))
#define pb push_back
using namespace std;

const int MAXN = 1005;

int c, T, n, x[MAXN], d;

int dis[MAXN][MAXN], nxt[MAXN];
bool vis[MAXN][MAXN];

void solve() {
  cin >> n >> d;
  rep(i, 1, n) cin >> x[i]; 
  
  rep(i, 1, n) rep(j, 1, n) vis[i][j] = 0;
  rep(i, 1, n) {
    rep(j, i, n) {
      if (x[j] - x[i] > d) break;
      nxt[i] = j;
    }
  }
  rep(i, 1, n) rep(j, 1, n) dis[i][j] = n + 1;
  rep(i, 1, n) {
    dis[i][i] = 0;
    int c = 0;
    for (int j = i; ;) {
      if (nxt[j] == j) break;
      ++c;
      rep(t, j + 1, nxt[j]) dis[i][t] = c;
      j = nxt[j], vis[i][j] = 1;
    }
  }
  int ans = 0;
  rep(i, 1, n) rep(j, i + 1, n) {
    if (dis[i][j] == n + 1) continue;
    int cnt = 0;
    rep(p, i + 1, j - 1) {
      if (dis[i][p] + dis[p][j] == dis[i][j]) cnt++;
    }
    ans += (cnt == dis[i][j]);
  }
  cout << ans << '\n';
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> c >> T; T--; solve());
  return 0;
}
// g++ migrate.cpp -o migrate -std=c++14 && ./migrate