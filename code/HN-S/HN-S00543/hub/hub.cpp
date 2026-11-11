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
    if (13 <= tid && tid <= 14) {
      int m = n / 2;
      if (k == n) {
        cout << 0 << '\n';
      } else if (k >= m) {
        cout << 1 << '\n';
      } else {
        cout << (m + 5) / 4 - (k - 2) / 4 << '\n';
      }
      continue;
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
    vector<int> f;
    auto get_f = [&](int x) -> int {
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
      int s;
      if (~d[py] & 1) {
        get_ht(get_ht, pz, -1);
        c.assign(ht[pz] + 1, 0);
        get_c(get_c, pz, -1);
        s = ht[pz];
        if (f.size() < ht[pz]) {
          f.resize(ht[pz]);
        }
        for (int i = 0; i < ht[pz]; ++i) {
          f[i] += c[i];
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
        if (f.size() < ht[pz] + 1) {
          f.resize(ht[pz] + 1);
        }
        for (int i = 0; i < ht[pz]; ++i) {
          f[i] += c[i];
        }
        ++f[ht[pz]];
        f.push_back(1);
      }
      return s;
    };
    auto calc = [&](int x, int y) -> int {
      f.clear();
      ban = y;
      int sx = get_f(x);
      ban = x;
      int sy = get_f(y);
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
      for (int i = max(sx, sy) - 1; i >= 0; --i) {
        if (_k < f[i]) {
          return i + 1;
        }
        _k -= f[i];
      }
      return 0;
    };
    int ans;
    {
      ban = -1, f.clear();
      int s = get_f(0);
      // cerr << 0 << ' ' << s << " | ";
      // for (int i : f) {
      //   cerr << i << ' ';
      // }
      // cerr << endl;
      ans = 0;
      int _k = k - 1;
      for (int i = s - 1; i >= 0; --i) {
        if (_k < f[i]) {
          ans = i + 1;
          break;
        }
        _k -= f[i];
      }
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