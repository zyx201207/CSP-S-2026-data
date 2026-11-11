// JY is cute. OvO
#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
using LL = __int128; 
template<typename T = ll>
T qr() {
  T x = 0; 
  int c = getchar(), e = 1; 
  for (; !isdigit(c); c = getchar()) if (c == '-') e = -1; 
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48); 
  return e * x; 
}
template<typename T>
void qr(T& x) {
  x = qr(); 
}
template<typename T> 
void qw(T x) {
  if (x < 0) putchar('-'), x = -x; 
  if (x > 9) qw(x / 10); 
  putchar(x % 10 + '0'); 
}
constexpr int MAXN = 235235; 
constexpr ll INF = 235235235235235ll; 
int main() {
  freopen("string.in", "r", stdin); 
  freopen("string.out", "w", stdout); 
  int n; 
  cin >> n; 
  vector<ll> a(n + 2, 0), b(n + 2, 0); 
  vector<ll> pa(n + 2, 0); 
  vector<ll> pb(n + 2, 0); 
  vector<char> c(n + 2, 0), d(n + 2, 0); 
  ll L = 0; 
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i] >> c[i]; 
    pa[i] = pa[i - 1] + a[i];
  }
  b = a; 
  reverse(b.begin(), b.end()); 
  d = c; 
  reverse(d.begin(), d.end()); 
  for (int i = 1; i <= n; ++ i) {
    pb[i] = pb[i - 1] + b[i]; 
  }
  vector<ll> p(1, 0); 
  for (int i = 1; i <= n; ++ i) {
    p.push_back(pa[i]); 
    p.push_back(pb[i]); 
  }
  p.push_back(0); 
  sort(p.begin() + 1, p.begin() + 1 + (n << 1)); 
  int nn = unique(p.begin() + 1, p.begin() + 1 + (n << 1)) - p.begin(); 
  vector<int> A(nn + 2, 0), B(nn + 2, 0); // { raw_index }
  for (int i = 1; i <= nn; ++ i) {
    auto it = lower_bound(pa.begin(), pa.end() - 1, p[i]) ; 
    A[i] = it - pa.begin(); 
  }
  for (int i = 1; i <= nn; ++ i) {
    auto it = lower_bound(pb.begin(), pb.end() - 1, p[i]) ; 
    B[i] = it - pb.begin(); 
  }
  ll ans = 0; 
  for (int i = 1; i <= nn; ++ i) {
    if (c[A[i]] != d[B[i]]) {
      // cerr << "p_" << i << ": " << p[i] << ' ';  
      ans += p[i] - p[i - 1]; 
      // cerr << "now ans: " << ans << " idx: " << i << '\n'; 
    }
    // if (p[i] > p[nn] / 2) {
    //   // break; 
    //   cerr << "ED!\n"; 
    // }
    // if (ans > 24500) {
    //   break; 
    // }
    if (n & 1 && A[i] == n + 1 - B[i] || !(n & 1) && A[i] == n - B[i]) { // ??? why this is right!!!!
      break; 
    }

  }
  cout << ans << '\n'; 
  // cerr << "tot_len: " << p[nn] << '\n'; 
  // cerr << 





  // ll lst_cut = 1;
  // vector<pair<ll,ll>> r(1, {0,0});  
  // for (ll i = 1, j = 1, li = 0, lj = 0; i <= n, j <= nn; ++ i) {
  //   if (p[j] == pa[i]) {
  //   }
  // }
  
  // ll t_tot = 0; 
  // if (L & 1) {
  //   ll mid = (L + 1) >> 1; 
  // } else {
  //   ll mid = (L + 0) >> 1; 
  //   ll rt_endi = -1, rt_endj = -1; 
  //   for (int i = 1; i <= n; t_tot += a[i], ++ i) {
  //     if (bega[i] <= mid && mid <= enda[i]) {
  //       rt_endi = i; 

  //     }
  //   }
  // }
  
  return 0; 
}