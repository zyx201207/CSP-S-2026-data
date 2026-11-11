#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define ll long long
#define topQ priority_queue
#define bint __int128

inline int in () {
 int x = 0; bool f = false; char ch = getchar();
 while (!isdigit(ch)) f |= ch == '-', ch = getchar();
 while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
 return f ? -x : x;
}

constexpr int N = 5e5 + 1e3, Mod = 998244353;

int n, m, a[N], s[N], ans = 1;

signed main() { freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
 n = in(), m = in(); for (int i = 1; i <= n; a[i] = in(), i++);
 sort(a + 1, a + n + 1); for (int i = 1; i <= n; s[i] = s[i - 1] + a[i], i++);
 for (int i = 2; i <= n; i++) {
  int L = 0, R = i;
  while (L + 1 < R) {
   int M = (L + R) >> 1;
   if (1ll * (i - M + 1) * a[i] - s[i] + s[M - 1] > m) L = M;
   else R = M;
  }
  ans = max(ans, i - R + 1);
 } printf("%lld\n", ans);
 return 0;
}

