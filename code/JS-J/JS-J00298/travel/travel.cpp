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
  freopen("travel.in", "r", stdin); 
  freopen("travel.out", "w", stdout); 
  string a, x, b, y; 
  cin >> a >> x >> b >> y; 
  int r1 = a == b; 
  int r2 = r1 && x[0] == y[0] && x[1] == y[1]; 
  int r3 = r2 && (x[2] == 'A' && y[2] == 'B' || x[2] == 'A' && y[2] == 'C'  
               || x[2] == 'B' && y[2] == 'A' || x[2] == 'B' && y[2] == 'C'
               || x[2] == 'C' && y[2] == 'A' || x[2] == 'C' && y[2] == 'B'
               || x[2] == 'D' && y[2] == 'F' || x[2] == 'F' && y[2] == 'D'
               ); 
  int r4 = r2 && (x[2] == 'A' && y[2] == 'B' || x[2] == 'B' && y[2] == 'A'  
               || x[2] == 'B' && y[2] == 'C' || x[2] == 'C' && y[2] == 'B'
               || x[2] == 'D' && y[2] == 'F' || x[2] == 'F' && y[2] == 'D'
               ); 
  cout << r1 << r2 << r3 << r4 << '\n'; 
  return 0; 
}