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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> e(n);
    for (int i = 1, x, y; i < n; ++i) {
      cin >> x >> y, --x, --y;
      e[x].push_back(y), e[y].push_back(x);
    }
    vector<int> fa(n), d(n), ht(n), c;
    int ban = -1;
    auto get_dep = [&](auto &&self, int x, int _f) -> void {
      fa[x] = _f, d[x] = (_f == -1 ? 0 : d[_f] + 1);
      for (int i : e[x]) {
        if (i != _f && i != ban) {
          self(self, i, x);
        }
      }
    };
    auto get_ht = [&](auto &&self, int x, int _f) -> void {
      ht[x] = 0;
      for (int i : e[x]) {
        if (i != _f && i != ban) {
          self(self, i, x);
          ht[x] = max(ht[x], ht[i] + 1);
        }
      }
    };
    auto get_c = [&](auto &&self, int x, int _f) -> void {
      ++c[ht[x]];
      for (int i : e[x]) {
        if (i != _f && i != ban) {
          self(self, i, x);
        }
      }
    };
    auto get_f = [&](int x) -> pair<int, vector<int>> {
      // cerr << x << ' ' << ban << endl;
      fill(d.begin(), d.end(), -1);
      get_dep(get_dep, x, -1);
      int px = max_element(d.begin(), d.end()) - d.begin();
      get_dep(get_dep, px, -1);
      int py = max_element(d.begin(), d.end()) - d.begin();
      int pz = py;
      for (int i = d[py] / 2; i; --i, pz = fa[pz]) {
      }
      // cerr << x << ' ' << ban << ' ' << pz << ' ' << d[py] << endl;
      vector<int> f;
      int s;
      if (~d[py] & 1) {
        get_ht(get_ht, pz, -1);
        c.assign(ht[pz] + 1, 0);
        get_c(get_c, pz, -1);
        s = ht[pz];
        for (int i = 0; i < ht[pz]; ++i) {
          f.push_back(c[i]);
        }
      } else {
        get_ht(get_ht, pz, fa[pz]);
        get_ht(get_ht, fa[pz], pz);
        // if (ht[pz] != ht[fa[pz]]) {
        //   cerr << pz << ' ' << fa[pz] << ' ' << ht[pz] << ' ' << ht[fa[pz]] << ' ' << d[py] << endl;
        //   get_ht(get_ht, px, -1);
        //   cerr << ht[px] << ' ' << ht[pz] << endl;
        //   get_ht(get_ht, py, -1);
        //   cerr << ht[py] << ' ' << ht[fa[pz]] << endl;
        //   get_dep(get_dep, py, -1);
        //   // get_dep(get_dep, pz, -1);
        //   int pu = max_element(d.begin(), d.end()) - d.begin();
        //   cerr << px << ' ' << py << ' ' << pu << ' ' << d[pu] << endl;
        //   assert(0);
        // }
        c.assign(ht[pz] + 1, 0);
        get_c(get_c, pz, fa[pz]);
        get_c(get_c, fa[pz], pz);
        s = ht[pz] + 1;
        for (int i = 0; i < ht[pz]; ++i) {
          f.push_back(c[i]);
        }
        f.push_back(1);
      }
      return {s, f};
    };
    auto calc = [&](int x, int y) -> int {
      ban = y;
      auto [sx, fx] = get_f(x);
      ban = x;
      auto [sy, fy] = get_f(y);
      // cerr << x << ',' << y << '\n';
      // cerr << "  " << sx << " | ";
      // for (int i : fx) {
      //   cerr << i << ' ';
      // }
      // cerr << endl;
      // cerr << "  " << sy << " | ";
      // for (int i : fy) {
      //   cerr << i << ' ';
      // }
      // cerr << endl;
      int _k = k - 2;
      for (; sx || sy;) {
        if (sx > sy || sx == sy && fx[sx - 1] < fy[sy - 1]) {
          if (_k >= fx[sx - 1]) {
            _k -= fx[--sx];
          } else {
            break;
          }
        } else {
          if (_k >= fy[sy - 1]) {
            _k -= fy[--sy];
          } else {
            break;
          }
        }
      }
      return max(sx, sy);
    };
    int ans;
    {
      ban = -1;
      auto [s, f] = get_f(0);
      // cerr << 0 << ' ' << s << " | ";
      // for (int i : f) {
      //   cerr << i << ' ';
      // }
      // cerr << endl;
      int _k = k - 1;
      for (; s; ) {
        if (_k >= f[s - 1]) {
          _k -= f[--s];
        } else {
          break;
        }
      }
      ans = s;
    }
    for (int i = 0; i < n; ++i) {
      for (int j : e[i]) {
        if (j < i) {
          ans = min(ans, calc(i, j));
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}