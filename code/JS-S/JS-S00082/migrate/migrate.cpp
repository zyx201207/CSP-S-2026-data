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
using T = long long; 
struct Edge {
  int u, v; 
  ll w; 
}; 
struct To {
  int v; 
  ll w; 
  const bool operator>(const To& that) const {
    return w > that.w; 
  }
}; 
void solve() {
  ll n, d; 
  cin >> n >> d; 
  vector<ll> x(n + 2); 
  vector<vector<To>> g(n + 1, vector<To>{}); 
  for (int i = 1; i <= n; ++ i) {
    cin >> x[i]; 
  }
  // cerr << "input done\n";
  for (int i = 1; i <= n; ++ i) {
    for (int j = i + 1; j <= n; ++ j) {
      if (x[j] - x[i] <= d) {
        // g[i].push_back({j, x[j] - x[i]}); 
        // g[j].push_back({i, x[j] - x[i]}); 

        g[i].push_back({j, 1}); 
        // g[j].push_back({i, 1});
        // cerr << "+\n"; 
      }
    }
  }
  
  // vector<vector<ll>> fr(n + 2, vector<ll>(n + 2, 0)); 
  ll tot = 0; 
  for (int s = 1; s <= n; ++ s) {
    vector<ll> dis(n + 1, LLONG_MAX / 2); 
    vector<int> vis(n + 1, false); 
    vector<ll> cnt(n + 1, 0); 
    // priority_queue<To, vector<To>, greater<To>> pq; 
    // pq.push({s, 0}); 
    queue<int> q; 
    q.push(s); 
    dis[s] = 0; 
    cnt[s] = 1; 
    // while (pq.size()) {
    while (q.size()) {
      // auto t1 = pq.top();
      // pq.pop();  
      // auto u = t1.v;
      // auto w = t1.w;
      auto u = q.front(); 
      q.pop(); 
      if (vis[u]) continue; 
      vis[u] = true; 
      for (auto& t2 : g[u]) {
        auto v = t2.v;
        auto w = t2.w;
        // cerr << "uv " << u << ' ' << v << '\n'; 
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          cnt[v] = cnt[u]; 
          // cerr << "push: " << u << '\n'; 
          // pq.push({v, dis[v]}); 
          q.push(v); 
        } else if (dis[v] == dis[u] + w) {
          cnt[v] += cnt[u]; 
        }
      }
    }
    // cerr << "dis: " << dis[n] << '\n';  
    for (int t = 1; t <= n; ++ t) {
      // cerr << s << " cnt " << t << ": " << cnt[t] << '\n'; 
      if (cnt[t] == 2) {
        ++tot; 
      }
    }
  }
  // qw(tot),putchar('\n');
  cout << tot << '\n'; 
}
int main() {
  freopen("migrate.in", "r", stdin); 
  freopen("migrate.out", "w", stdout); 
  int c, t; 
  cin >> c >> t; 
  for (; t--; ) {
    solve(); 
  }
  return 0;  // must!!!
}
// this is the template
