#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFILE = "hub";
ifstream cin(kFILE + ".in");
ofstream cout(kFILE + ".out");
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tid, tt;
  for (cin >> tid >> tt; tt--; ) {
    int n, K;
    cin >> n >> K;
    vector<vector<int>> e(n);
    for (int i = 1, x, y; i < n; ++i) {
      cin >> x >> y, --x, --y;
      e[x].push_back(y), e[y].push_back(x);
    }
    vector<int> ht(n);
    vector<vector<vector<int>>> f(n), g(n);
    auto dfs = [&](auto &&self, int x, int _f, int L) -> void {
      for (int i : e[x]) {
        if (i != _f) {
          self(self, i, x, L);
          ht[x] = max(ht[x], ht[i] + 1);
        }
      }
      vector<vector<int>> fx(3, vector<int>(ht[x] + 1, 1e9)), gx(3, vector<int>(ht[x] + 1, 1e9));
      fx[1][0] = 1, gx[0][0] = 0;
      for (int i : e[x]) {
        if (i != _f) {
          vector<vector<int>> _fx(3, vector<int>(ht[x] + 1, 1e9)), _gx(3, vector<int>(ht[x] + 1, 1e9));
          for (int cc = 0; cc < 3; ++cc) {
            for (int cx = 0; cx < 3; ++cx) {
              int cr = cc + cx;
              for (int j = 0; j <= ht[i]; ++j) {
                for (int k = 0; k <= ht[x]; ++k) {
                  int _cr = cr - (j == 0 && k == 0);
                  if (0 <= _cr && _cr < 3) {
                    _fx[_cr][min(j + 1, k)] = min(_fx[_cr][min(j + 1, k)], fx[cx][k] + f[i][cc][j]);
                  }
                  if (cr < 3) {
                    if (k + j + 1 <= L) {
                      _fx[cr][k] = min(_fx[cr][k], fx[cx][k] + g[i][cc][j]);
                    } else {
                      _gx[cr][j + 1] = min(_gx[cr][j + 1], fx[cx][k] + g[i][cc][j]);
                    }
                    _gx[cr][max(j + 1, k)] = min(_gx[cr][max(j + 1, k)], gx[cx][k] + g[i][cc][j]);
                    if (k + j + 1 <= L) {
                      _fx[cr][j + 1] = min(_fx[cr][j + 1], gx[cx][k] + f[i][cc][j]);
                    } else {
                      _gx[cr][k] = min(_gx[cr][k], gx[cx][k] + f[i][cc][j]);
                    }
                  }
                }
              }
            }
          }
          swap(fx, _fx), swap(gx, _gx);
        }
      }
      f[x] = fx, g[x] = gx;
    };
    // dfs(dfs, 0, -1, 1);
    // int mn = 1e9;
    // for (int i = 0; i < 3; ++i) {
    //   mn = min(mn, *min_element(f[0][i].begin(), f[0][i].end()));
    // }
    // cerr << mn << '\n';
    int l = 0, r = n;
    for (int m; l < r; ) {
      m = (l + r) >> 1;
      dfs(dfs, 0, -1, m);
      int mn = 1e9;
      for (int i = 0; i < 3; ++i) {
        mn = min(mn, *min_element(f[0][i].begin(), f[0][i].end()));
      }
      if (mn <= K) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << '\n';
  }
  return 0;
}