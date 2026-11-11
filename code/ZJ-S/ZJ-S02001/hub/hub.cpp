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
constexpr $d N = 1000005;
$d dp[4005][4005], dep[N], mdep[n];
std::vector<$d> G[N];
void dfs1($d u, $d f) {
    mdep[u] = dep[u] = dep[f] + 1;
    for(auto v: G[u]) if(v != f) {
        dfs1(v, u);
        mdep[u] = max(dep[u], mdep[u]);
    }
}
void dfs2($d u, $d f) {
    rep(i, 0, mdep[u] - dep[u])
        dp[u][i] = 1;
    for(auto v : G[u])
        if(v != f) {
            dfs2(v, u);
            rep(j, 0, mdep[v] - dep[v])
                dp[u][j] += dep[v][j];
        }
}
void dfs3($d u, $d f) {

}
$d main() {
   std::ios::sync_with_stdio(0);std::cin.tie(0);
   ret 0;
}
/*
must cons a fangan, min in leaf.

and least one node on zhijin.

tiaozhengfa. (ling ... is zhijin)

so
d:
 ------U    V-----
binary + two-pointers(make middle farthest is <= mid)(changpou - like zhuanyi, O(n))
O(nlogn)
*/