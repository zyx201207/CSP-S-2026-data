#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l);i <= (r);i ++)
#define dwn(i, l, r) for(iny i = (l);i >= (r);i --)
#define FaILurEg(s) freopen(s ".in","r",stdin);freopen(s ".out","w",stdout)
typedef int $d;typedef long long $q;
#define ret return
template<typename T>inline T max(T a, T b){ret a > b ? a : b;}
template<typename T>inline  T min(T a, T b){ret a < b ? a : b;} \
template<typename T>void print(T x) {
   std::cout << x;
}
template<typename T,typename  ...Args >void print(T x, Args...Arg) {
   std::cout << x;
   print(Arg...);
}
template<typename T>void read(T &x) {
   std::cin >> x;
}
template<typename T,typename  ...Args >void read(T& x, Args&...Arg) {
   std::cin >> x;
   read(Arg...);
}
constexpr $d N = 500005;
$d n;$q m;
$q a[N];
$d main() {
   FaILurEg("crystal");
   std::ios::sync_with_stdio(0);std::cin.tie(0);
   read(n, m);
   rep(i, 1, n) read(a[i]);
   std::sort(a+1, a + 1 + n);
   $d l = 1, Ans = 0;$q need = 0;
   rep(i, 1, n) {
      while(need > m) 
         need -= (a[i] - a[l ++]);
      Ans = max(Ans, i - l + 1);
      if(i != n)
         need += (i - l + 1) * (a[i + 1] - a[i]);
   }
   print(Ans, "\n");
   ret 0;
}
/*
青春青春渡時機
孤船有岸等何時
*/