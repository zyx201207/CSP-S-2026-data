#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 1e5 + 5;

struct sgt { // signle modify segment max
  vector<int> t;
  int n;
  sgt(int _n = 0) { n = _n, t.assign(2 * n + 1, 0); }
  void upd(int p, int v) {
    t[p += n - 1] = v;
    for (; p >>= 1; ) t[p] = max(t[p << 1], t[p << 1 | 1]);
  }
  int qry(int l, int r) {
    int ans = 0;
    for (l += n - 1, r += n - 1; l <= r; l >>= 1, r >> 1) {
      if (l & 1) ans = max(ans, t[l ++]);
      if (~r & 1) ans = max(ans, t[r --]);
    }
    return ans;
  }
};

struct bits {
  vector<int> c;
  int n;
  bits(int _n = 0) { n = _n, c.assign(n + 1, 0); }
  void upd(int p, int v) {
    for (; p <= n; p += p & (-p)) c[p] += v;
  }
  int qry(int p) {
    int ans = 0;
    for (; p; p -= p & (-p)) ans += c[p];
    return ans;
  }
};

void fakemain() {

}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  };
  fre("temp");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T --) fakemain();
  return 0;
}