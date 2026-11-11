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
#define pb push_back
constexpr $d N = 505, M = 500005;
constexpr $q INF = 0x3f3f3f3f3f3f3f3f;
$d c, n, m, d, q;
$d w[M];
std::vector<std::pair<$d, $d> >G[M];
$q dis[N][N];
$d main() {
   FaILurEg("subway");
   std::ios::sync_with_stdio(0);std::cin.tie(0);
   read(c, n, m, d, q);
   rep(i, 1, m)read(w[i]);
   rep(i, 1, n){
      $d k;read(k);
      rep(j, 1, k) {
         $d a, t;read(a, t);
         G[a].pb({i, t});
      }
   }
   rep(i, 1, n) rep(j, 1, n) if(i != j) dis[i][j] = INF;
   rep(i, 1, m) {
      for(auto pp : G[i]) 
         for(auto qq : G[i]) if(pp.first != qq.first){
            dis[pp.first][qq.first] = min(dis[pp.first][qq.first], ($q)pp.second + qq.second);
         }
   }
   rep(k, 1, n)
      rep(i, 1, n)
         rep(j, 1, n)
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
   rep(i, 1, q) {
      $d u, v;
      read(u, v);
      $q Ans = INF;
      for(auto pp : G[u])
         for(auto qq : G[v])
            Ans = min(Ans, pp.second + qq.second + dis[pp.first][qq.first]);
            //print("check : ", pp.first ,' ', qq.first, ' ', pp.second, ' ', qq.second, ' ', dis[pp.first][qq.first], '\n');
      print(Ans + w[u] + w[v], '\n');
   }
   ret 0;
}
/*
50minT1 ...
万一过了呢。
*/