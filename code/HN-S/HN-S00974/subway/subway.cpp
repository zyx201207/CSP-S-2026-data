#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#define inf 1000000000000000
using namespace std;
using ll = long long;
const int maxm = 500010;
const int maxn = 510;
int rr;
int n, m, d, q;
ll a[maxm], f[maxn][maxn];
vector <pair <int, ll>> p[maxm];
int main () {
  cin.tie (0)->sync_with_stdio (false);
  freopen ("subway.in", "r", stdin);
  freopen ("subway.out", "w", stdout);

  cin >> rr >> n >> m >> d >> q;


  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int len; cin >> len;
    for (int j = 1; j <= len; j++) {
      int x; ll v; cin >> x >> v;
      p[x].push_back ({i, v});
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) f[i][j] = inf;

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < p[i].size (); j++) {
      for (int k = j + 1; k < p[i].size (); k++) {
        int x = p[i][j].first;ll vx = p[i][j].second;
        int y = p[i][k].first;ll vy = p[i][k].second;
        if (x != y) {
          f[x][y] = min (f[x][y], vx + vy);
          f[y][x] = min (f[y][x], vx + vy);
        }
      }
    } 
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[i][j] = min (f[i][j], f[i][k] + f[k][j]);
      }
    }
  }

  // for (auto [x, vx] : p[2]) cout << x << ' ' << vx << endl;
  // cout << endl;
  // for (auto [x, vx] : p[3]) cout << x << ' ' << vx << endl;
  // cerr << f[1][2] << endl;
  while (q--) {
    int xi, yi; cin >> xi >> yi;
    ll res = inf;
    for (int i = 0; i < p[xi].size (); i++) {
      for (int j = 0; j < p[yi].size (); j++) {
        int x = p[xi][i].first;ll vx = p[xi][i].second;
        int y = p[yi][j].first;ll vy = p[yi][j].second;
        res = min (res, vx + f[x][y] + vy);
      }
    }
    cout << res + a[xi] + a[yi] << '\n';
  }

  // cerr << clock () << '\n';

  return 0;
}

/*
 g++ -std=c++14 -o2 tmp.cpp -o _ && ./tmp
 diff -b -B tmp1.ans tmp.out
 */