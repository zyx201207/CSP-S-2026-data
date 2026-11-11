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
const int N = 1e5 + 5, mod = 998244353;
int power(int x, int y = mod - 2) {
  int ans = 1;
  for (; y; y >>= 1, x = 1LL * x * x % mod)
    if (y & 1) ans = 1LL * ans * x % mod;
  return ans;
}
int fc[N], fv[N], inv[N];
void init(int n = N - 5) {
  fc[0] = 1;
  rep (i, 1, n) fc[i] = 1LL * i * fc[i - 1] % mod;
  fv[n] = power(fc[n]);
  rrp (i, n, 1) fv[i - 1] = 1LL * i * fv[i] % mod;
  inv[1] = 1;
  rep (i, 2, n) inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
}

int binom(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ULL * fc[n] * fv[m] % mod * fv[n - m] % mod;
}

void fakemain() {
  init(), debug(binom(4, 2));
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