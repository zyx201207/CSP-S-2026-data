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

constexpr int Mod = 998244353, N = 5e5 + 1e3;

int n, m, a[N], qwq[N]; bool b[N]; stack<int> stk;

signed main() { freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
 n = in(), m = in();
 for (int i = 1; i <= n; a[i] = in(), i++);
 if (n <= 5000) {
  for (int i = 1; i <= n; i++) {
   for (int j = 1; j <= m; j++) {
    b[j] = false;
   }
   for (int j = i; j <= n; j++) {
    if (b[a[j]]) {
     while (!stk.empty() && stk.top() ^ a[j]) b[stk.top()] = false, stk.pop();
    } else {
     stk.push(a[j]);
     b[a[j]] = true;
    }
   }
   while (!stk.empty()) qwq[stk.top()]++, stk.pop();
  }
  for (int i = 1; i <= m; i++) printf("%lld%c", qwq[i], i == m ? '\n' : ' ');
 } else if (m <= 2) {
  if (m == 1) printf("%lld\n", n);
  else if (m == 2) {
   int cnt1 = 0, cnt2 = 0;
   for (int i = 1; i <= n; i++) cnt1 += a[i] == 1 || a[n] == 1, cnt2 += a[i] == 2 || a[n] == 2;
   printf("%lld %lld\n", cnt1, cnt2);
   return 0;
  }
 } else {
  for (int i = 1; i <= n; ) {
   int j = i; while (j <= n && a[i] == a[j]) j++;
   qwq[a[i]] = j - 1;
   i = j;
  }
  for (int i = 1; i <= m; i++) printf("%lld%c", qwq[i], i == m ? '\n' : ' ');
 }
 return 0;
}

