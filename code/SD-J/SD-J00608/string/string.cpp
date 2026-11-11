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

int n, a[N], g[N], ans; char s[N][3];

signed main() { freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
 n = in(); for (int i = 1; i <= n; a[i] = in(), scanf("%s", s[i] + 1), g[i] = g[i - 1] + a[i], i++);
 for (int i = 1, j = n, r = g[n], l = 0; i < j; ) {
  int len1 = g[i] - l, len2 = r - g[j - 1];
  //printf("#line 24 : i = %lld, j = %lld, len1 = %lld, len2 = %lld, l = %lld, r = %lld\n", i, j, len1, len2, l, r);
  //printf("#line 25 : si = %c, sj = %c\n", s[i][1], s[j][1]);
  if (len1 > len2) {
   if (s[i][1] != s[j][1]) ans += len2;
   j--; r = g[j]; l += len2;
   continue;
  } else {
   if (s[i][1] != s[j][1]) ans += len1;
   //printf("#line 31 : ANS = %lld\n", ans);
   i++; l = g[i - 1]; r -= len1;
  }
 } printf("%lld\n", ans);
 return 0;
}

