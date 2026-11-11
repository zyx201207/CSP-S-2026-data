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
const int N = 5e5 + 5;

int n;
LL m, a[N];

void fakemain() {
  cin >> n >> m;
  rep (i, 1, n) cin >> a[i];
  sort(a + 1, a + 1 + n);
  LL cnt = 0, sum = 0;
  int j = 1, ans = 0;
  rep (i, 1, n) {
    sum += a[i], cnt ++;
    while (cnt * a[i] - sum > m)
      sum -= a[j ++], -- cnt;
    ans = max(ans, i - j + 1);
  }
  cout << ans << '\n';
}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  };
  fre("crystal");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T --) fakemain();
  cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}