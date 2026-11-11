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
int n, m; 
ll a[MAXN], c[MAXN]; 
int cnt[32]; 
int main() {
  freopen("and.in", "r", stdin); 
  freopen("and.out", "w", stdout); 
  cin >> n >> m; 
  for (int i = 1; i <= n; ++ i) cin >> a[i], c[i] = a[i]; 
  for (int b = 0; b <= 31; ++ b) {
    for (int i = 0; i <= n; ++ i) {
      if (a[i] & (1 << b)) {
        ++cnt[b]; 
      }
    }
  }
  for (int b = 0; b <= 30; ++ b) {
    if (cnt[b] < m) {
      for (int i = 1; i <= n; ++ i) {
        if (c[i] & (1 << b)) {
          c[i] ^= 1 << b; 
        }
      }
    }
  }
  sort(c + 1, c + 1 + n, greater<ll>()); 
  // for (int i = 1; i <= n; ++ i) {
  //   cerr << "c_" << i << ": " << c[i] << '\n'; 
  // }
  ll ans = ~0ll; 
  for (int i = 1; i <= m; ++ i) {
    ans &= c[i]; 
  }
  cout << ans << '\n'; 
  return 0; 
}