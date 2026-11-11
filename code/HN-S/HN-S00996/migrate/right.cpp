#include<bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i <= r; i ++)
#define rrp(i,l,r) for (int i = l; i >= r; i --)
using namespace std;
#ifdef LOCAL
#define debug(x) (cerr << #x << " = " << x << '\n')
#else
#define debug(x) void(0)
#endif
typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 2e6 + 5;

int n, f[N], g[N], pre[N], suf[N];
LL a[N], d;

void get(int *dp, int *pre) {
  static int f[N];
  pre[0] = 1, f[1] = f[0] = 0;
  rep (i, 1, n) {
    int &j = pre[i] = pre[i - 1];
    while (a[i] - a[j] > d) ++ j;
  }
  // rep (i, 1, n) cerr << pre[i] << " \n"[i == n];
  rep (i, 1, n) {
    int j = pre[i];
    if (j == i) {
      f[i] = 0;
    } else if (j + 1 == i) {
      f[i] = f[j] + 1;
    } else {
      f[i] = f[j] + (i - j);
      f[i] -= j - pre[j + 1];
    }
    // if (j == i || (i < n && a[i + 1] - a[j] <= d)) {
    //   dp[i] = 0;
    // } else if (j + 1 == i || i == n) {
    //   dp[i] = f[i];
    // } else {
    //   dp[i] = f[i] - (i - pre[i + 1]);
    // }
  }
  rep (i, 1, n) dp[i] = f[i];
  // rep (i, 1, n) cerr << f[i] << " \n"[i == n];
}

LL solve() {
  // rep (i, 1, n) cerr << f[i] << ' ' << g[i] << '\n';
  static int pre[N];
  pre[1] = 1; LL ans = 0;
  rep (i, 2, n) {
    int &j = pre[i] = pre[i - 1];
    while (a[i] - a[j] > d) ++ j;
    if (j + 1 < i) {
      int x = pre[j + 1], y = pre[j + 2];
      if (x < y) {
        int rig = 1, lef = 0;
        if (i < n) {
          int to = suf[i];
          if (i < to) {
            if (a[to] - a[i - 1] > d) {
              rig += g[to] + 1;
            }
          }
        }
        if (x > 1) {
          int to = pre[x];
          if (to < x) {
            if (a[x + 1] - a[to] > d)
              lef += f[to] + 1;
          }
        }
        ans += (LL)(y - x + lef) * rig;
      // cerr << ":::" << i << ' ' << lef << ' ' << rig << '\n';
      // cerr << x << ' ' << y << '\n';
      }
      // cerr << x << ' ' << y << ' ' << f[x] << '\n';
    }
  }
  return ans;
}

void fakemain() {
  cin >> n >> d;
  rep (i, 1, n) cin >> a[i];
  get(f, pre);
  rep (i, 1, n) a[i] = -a[i];
  reverse(a + 1, a + 1 + n);
  get(g, suf);
  rep (i, 1, n) a[i] = -a[i];
  reverse(a + 1, a + 1 + n);
  rep (i, 1, n) suf[i] = n - suf[i] + 1;
  reverse(g + 1, g + 1 + n);
  reverse(suf + 1, suf + 1 + n);
  rep (i, 1, n) cerr << suf[i] << " \n"[i == n];
  rep (i, 1, n) cerr << pre[i] << " \n"[i == n];
  cout << solve() << '\n';
}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  };
  fre("migrate");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1, c;
  cin >> c >> T;
  while (T --) fakemain();
  cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}