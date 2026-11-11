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
  freopen("subway.in", "r", stdin); 
  freopen("subway.out", "w", stdout); 
  cout << "You have no egg! \n"; 
  return 0;  // must!!!
}
// this is the template