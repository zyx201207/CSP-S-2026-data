#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
// #define int LL
const int maxn = 5e3 + 10;
int c, T;
int n; LL x[maxn], d;
int q[maxn << 2];
LL ans;
namespace sgt {
  struct Node {
    int mn, c;
  } t[maxn << 2];
  inline Node pushup(Node ls, Node rs) {
    if(ls.mn < rs.mn) return ls; 
    else if(rs.mn < ls.mn) return rs;
    else return {ls.mn, ls.c + rs.c};
  } 
  inline void modf(int u, int l, int r, int p, Node k) {
    if(l == r) {
      t[u] = k;
      return ; 
    }
    int mid = l + r >> 1;
    if(p <= mid) modf(u << 1, l, mid, p, k);
    if(p > mid) modf(u << 1 | 1, mid + 1, r, p, k); 
    t[u] = pushup(t[u << 1], t[u << 1 | 1]);
  }
  inline Node Q(int u, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return t[u]; 
    int mid = l + r >> 1;
    if(qr <= mid) return Q(u << 1, l, mid, ql, qr); 
    if(ql > mid) return Q(u << 1 | 1, mid + 1, r, ql, qr); 
    return pushup(Q(u << 1, l, mid, ql, qr), Q(u << 1 | 1, mid + 1, r, ql, qr)); 
  }
  inline void build(int u, int l, int r, int k) {
    if(l == r) {
      t[u] = {(int)1e9, 0};
      if(r == k) t[u] = {0, 1}; 
      return ;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid, k), build(u << 1 | 1, mid + 1, r, k); 
    t[u] = pushup(t[u << 1], t[u << 1 | 1]); 
  }
}
using namespace sgt;
inline void solve() {
  ans = 0; 
  cin >> n >> d;
  for(int i = 1; i <= n; ++ i) cin >> x[i]; 
  for(int i = 1; i < n; ++ i) {
    build(1, 1, n, i); 
    int p = i;
    for(int j = i + 1; j <= n; ++ j) {
      while(x[j] - x[p] > d) p ++ ;
      if(p == j) break;
      Node t = Q(1, 1, n, p, j);
      if(t.c == 2) ans ++ ;
      t.mn ++ ;     
      modf(1, 1, n, j, t); 
    }
  }
  cout << ans << '\n';
}
inline void solve2() {
  
}
signed main() {
  freopen("migrate.in", "r", stdin); 
  freopen("migrate.out", "w", stdout); 
  ios :: sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> c >> T;
  while(T -- ) {
    if(c <= 10) solve();
    else if(13 <= c && c <= 14) solve2();
  }
  return 0; 
}