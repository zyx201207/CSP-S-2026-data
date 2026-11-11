// Yan JING is very cute ! ! ! ! He/She will help me AK 2026 CSP-S2. 

/*
wo chang chang zhui yi guo qu

sheng ming shun jian ding ge zai nao hai

wo jiang bei hou de shi jian cai jian zhe die quan qu, rou nian cheng tian shang dup duo bai yun.

yun duo zhi jian yi you fen bie

*/

#include <bits/stdc++.h>
using namespace std; 
// using ll = long long;
using ll = __int128;
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
ll n, m;
ll a[MAXN], p[MAXN], P[MAXN], q[MAXN], Q[MAXN]; 
void good() {
  sort(a + 1, a + 1 + n, greater<>()); 
  vector<ll> div; /// fen ge xian de you mian de dian de bian hao
  for (ll i = 1; i <= n; ++ i) {
    if (a[i] != a[i - 1]) {
      div.push_back(i); 
      // cerr << "div_" << ": " << i << '\n';  
    }
  }
  ll ans = 0; 
  ll lsta = a[1]; 
  ll lstdone = 1; 
  ll lstuse = 0; 
  ll r1 = -1, r2 = -2; 
  for (ll I = 0; I < div.size() - 1; ++ I) {
    ll i = div[I]; 
    ll nx = div[I + 1]; 
    ll use = 0; 
    ll j = lstdone; 
    ll tmp = 0; 
    for (; use <= m - lstuse && j <= n; ++ j) {

      use += a[i] - a[j]; 
      // cerr << "i:" << i << " j:" << j; 
      // cerr << " now use: " << use << '\n'; 
      if (use > m - lstuse) {
        use -= a[i] - a[j]; 
        // cerr << "i:" << i << " use:" << use << " j:" << j << '\n'; 
        if (i == 1) {
          // cerr << "fff " << n * 
        }
        break; 
      }
    } // j: first dont valid
    // --j;
    // cerr << "[ " << i << ", " << j << " ] use: " << use << " lstuse: " << lstuse << '\n'; 
    lstdone = j; 
    lstuse = use - (a[i] - a[nx]) * (j - nx);
    // cerr << "[i, nx]: " << i << ' ' << nx << ' ' << "use: " <<  
    if (j - i > ans) {
      r1 = i, r2 = j; 
    }
    ans = max(ans, j - i); 

    if (I > 10) { //
      break; 
    }
  }
  qw(ans),putchar('\n'); 
  // cerr << "sum: " << n * *max_element(a + 1, a + 1 + n) - accumulate(a + 1, a + 1 + n, 0ll) << '\n'; 
  // cerr << "r1: " << r1 << " r2: " << r2 << '\n'; 
}
void brute( ) {
  sort(a + 1, a + 1 + n, greater<>()); 
  vector<ll> div; /// fen ge xian de you mian de dian de bian hao
  for (ll i = 1; i <= n; ++ i) {
    if (a[i] != a[i - 1]) {
      div.push_back(i); 
      // cerr << "div_" << ": " << i << '\n';  
    }
  }
  ll ans = 0; 
  ll r1 = -1, r2 = -1; 
  for (ll i = 1; i <= n; ++ i) {
    ll use = 0; 
    ll j = 1; 
    for (; (use + a[i] - a[j]) <= m && j <= n; ++ j) {
      use += a[i] - a[j]; 
    }
    if (j - i >= ans) {
      r1 = i, r2 = j; 
    }
    ans = max(ans, j - i); 
    if (j > n) {
      break; 
    }
    // if (I > 10) { //
    //   break; 
    // }
  }
  qw(ans),putchar('\n'); 
  qw(r1),putchar(' '),qw(r2),putchar('\n'); 
  // cerr << "sum: " << n * *max_element(a + 1, a + 1 + n) - accumulate(a + 1, a + 1 + n, 0ll) << '\n'; 
  // cerr << "r1: " << r1 << " r2: " << r2 << '\n'; 
}
int main() {
  freopen("crystal.in", "r", stdin); 
  freopen("crystal.out", "w", stdout); 
  qr(n),qr(m);
  for (int  i = 1; i <= n; ++ i) qr(a[i]); 
  sort(a + 1, a + 1 + n, greater<>()); 
  auto mx = *max_element(a + 1, a + 1 + n); 
  vector<ll> p(n + 2, 0); 
  for (int i = 1; i <= n; ++ i) p[i] = p[i - 1] + mx - a[i]; 
  ll ans = 0;  
  for (ll beg = 1; beg <= n; ++ beg) {

    // for (ll end = beg; end <= n; ++ end) { // [beg, end]
    //   ll cur = p[end] - p[beg - 1] - (end - beg + 1) * (mx - a[beg]); 
    //   if (cur <= m) {
    //     ans = max(ans, end - beg + 1); 
    //   }
    // } 
    ll l = beg, r = n; 
    ll now = 0; 
    while (l <= r) {
      auto mid = (r + l) >> 1; 
      if (p[mid] - p[beg - 1] - (mid - beg + 1) * (mx - a[beg]) <= m) {
        l = mid + 1; 
        now = mid - beg + 1; 
      } else {
        r = mid - 1; 
      }
    }
    ans = max(ans, now); 
  }
  qw(ans), putchar('\n'); 
  // bool chkB = 0; 
  // if (n >= 2) {
  //   chkB = 1; 
  //   ll d = a[2] - a[1]; 
  //   for (int i = 2; i <= n; ++ i) {
  //     if (a[i] - a[i-1] != d) {
  //       chkB = 0; 
  //     }
  //   }
  // }
  // if (chkB) {
  //   // cerr << "dengg\n"; 
  //   qw(min((ll)n, (ll)floor(0.5l * (1.l + sqrtl(1.l + 8.l * m / (a[2] - a[1]))))));
  //   putchar('\n'); 
  // } else {
  //   brute2(); 
  // }
  return 0; 
}
// this is the template