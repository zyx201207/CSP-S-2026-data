#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ull unsigned long long
#define REP(i, l, r)    for(int i = l;i <= r;i++)
#define DEP(i, r, l)    for(int i = r;i >= l;i--)
#define fi first
#define se second
#define pb push_back
#define pii std::pair<int, int> 


void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while(ch < '0' or ch > '9') {
    if (ch ==  '-') f = 1;
    ch = getchar();
  }
  while('0' <= ch and ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  if (f)  x = -x;
  read(oth...);
}

namespace YZLK{
  const int N = 5e5 + 10;
  int n, m;
  int a[N], s[N];
  int calc(int l, int r) {
    int sum = a[r] * (r - l + 1);
    sum -= (s[r] - s[l - 1]);
    return sum;
  }
  void main() {
    read(n, m);
    REP(i, 1, n)  read(a[i]);
    std::sort(a + 1, a + n + 1);
    REP(i, 1, n)  s[i] = s[i - 1] + a[i];
    int ans = 1;
    int l = 1;
    REP(r, 1, n) {
      while(calc(l, r) > m and l <= r) l++;
      ans = std::max(ans, r - l + 1);
    }
    std::cout << ans << '\n';
    return;
  }
}

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  int T = 1;
  // read(T);
  while(T--) {
    YZLK::main();
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}