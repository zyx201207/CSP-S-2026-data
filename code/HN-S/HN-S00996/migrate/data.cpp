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

int n = 8, v = 10, a[N];

void fakemain() {
  mt19937 rnd(time(0));
  cout << n << ' ' << rnd() % v << '\n';
  rep (i, 1, n) a[i] = rnd() % v;
  sort(a + 1, a + 1 + n);
  rrp (i, n, 1) a[i] -= a[1];
  rep (i, 1, n) a[i] += i;
  rep (i, 1, n) cout << a[i] << " \n"[i == n];
}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "w", stdout);
  };
  fre("migrate");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1, c;
  // cin >> c >> T;
  cout << "0 1\n";
  while (T --) fakemain();
  // cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}