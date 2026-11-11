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
const int N = 1e5 + 5;

void fakemain() {
  debug("Hello world");
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
  cerr << "time used: " << 1. * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}