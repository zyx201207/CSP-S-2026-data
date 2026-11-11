#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned
#define topQ priority_queue
#define bint __int128

inline int in() {
 int x = 0; bool f = false; char ch = getchar();
 while (!isdigit(ch)) f |= ch == '-', ch = getchar();
 while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
 return f ? -x : x;
}

constexpr int Mod = 998244353, N = 2e5 + 1e3;

int n, m, a[N], ans;
vector<int> v;

signed main() { freopen("and.in", "r", stdin); freopen("and.out", "w", stdout);
 n = in(), m = in(); for (int i = 1; i <= n; a[i] = in(), i++);
 for (int i = 1; i <= n; i++) v.push_back(a[i]);
 for (int i = 30; i >= 0; i--) {
  vector<int> qwq;
  for (auto x : v) if (x >> i & 1) qwq.push_back(x);
  if ((int)qwq.size() >= m) v = qwq, ans += 1 << i;
 } printf("%lld\n", ans);
 return 0;
}

