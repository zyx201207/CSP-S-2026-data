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

int n, len[N], cnt[N];
LL d, a[N];

void fakemain() {
  cin >> n >> d;
  rep (i, 1, n) cin >> a[i];
  int ans = 0;
  rep (i, 1, n) {
    int dis = 0, pos = i;
    rep (j, i, n) cnt[j] = len[j] = 0;
    cnt[i] = 1, len[i] = 0;
    // cerr << ":::" << i << '\n';
    rep (j, i + 1, n) {
      if (a[j] - a[pos] > d) {
        pos = j - 1, ++ dis;
      }
      if (a[j] - a[pos] > d) break;
      len[j] = dis + 1, cnt[j] = cnt[pos];
      if (pos - 1 >= i && len[pos - 1] == dis && a[j] - a[pos - 1] <= d) 
        cnt[j] += cnt[pos - 1];
      if (pos - 2 >= i && len[pos - 2] == dis && a[j] - a[pos - 2] <= d)
        cnt[j] += cnt[pos - 2];
      // cerr << pos << ' ' << len[j] << ' ' << cnt[j] << '\n';
      ans += (cnt[j] == 2);
    }
  }
  cout << ans << '\n';
}

signed main() {
  auto fre = [&](string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".ans").c_str(), "w", stdout);
  };
  fre("migrate");
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int T = 1, c;
  cin >> c >> T;
  while (T --) fakemain();
  cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}