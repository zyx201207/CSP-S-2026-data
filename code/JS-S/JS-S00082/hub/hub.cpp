// Yan JING is very cute ! ! ! ! He/She will help me AK 2026 CSP-S2. 
#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
using LL = __int128; 
const int MAXN = 532532; 
const ll INF = 532532532532532ll; 
template<typename T = ll> 
T qr() {
  T x = 0, e = 1; 
  int c = getchar(); 
  for (; !isdigit(c); c = getchar()) if (c == '-') e = -1; 
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48); 
  return x * e; 
}
template<typename T>
T qr(T& x) {
  return x = qr<T>(); 
}
template<typename T>
void qw(T x) {
  if (x < 0) x = -x, putchar('-'); 
  if (x > 9) qw(x / 10);
  putchar(x % 10 + '0'); 
  return; 
}
int main() {
  freopen("hub.in", "r", stdin); 
  freopen("hub.out", "w", stdout); 
  int c, t; 
  cin >> c >> t; 
  for (; t--; ) {
    int n, k; 
    vector<vector<int>> g(n + 2, vector<int>{}); 
    vector<int> candrt; 
    for (int i = 2; i <= n; ++ i) {
      int u, v;
      cin >> u >> v; 
      g[u].push_back(v); 
      g[v].push_back(u); 
      if (v == u + 1) {
        candrt.push_back(v); 
      }
    } 
    int rt = *min_element(candrt.begin(), candrt.end());
    int l = g[rt][0], r = g[rt][1]; 
    ll lmn =  LLONG_MAX;
    int lcnt = 1; 
    for (auto & v: g[l]) {
      if (v == l) continue; 
      l = v; 
    
      ++lcnt; 
    }
    int rcnt = 1; 
    for (auto & v: g[r]) {
      if (v == r) continue; 
      r = v; 
      ++rcnt; 
    }
    cout << lcnt + rcnt << '\n'; 
  }
  return 0;  // must!!!
}
// this is the template