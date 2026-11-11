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
constexpr int MAXN = 532532; 
constexpr ll INF = 235235235235235ll; 
int n, m; 
ll a[MAXN]; 
int nxt[MAXN], lst[MAXN]; // lst[value] = index 
ll cnt[MAXN]; 
void brute_force1() {
  vector<int> cnt(m + 1, 0); 
  for (int beg = 1; beg <= n; ++ beg) {
    vector<stack<int>> lst(m + 1); 
    // fill(lst + 1, lst + 1 + m, -1); 
    vector<int> exist(n + 1, true); 
    for (int i = beg; i <= n; ++ i) {
      if (lst[a[i]].size()) {
        for (int j = lst[a[i]].top(); j < i; ++ j) {
          exist[j] = false; 
          // cerr << j << " out! \n"; 
          if (lst[a[j]].size()) {
            lst[a[j]].pop(); 
          }
        }
      }
      lst[a[i]].push(i); 
    }
    for (int i = beg; i <= n; ++ i) {
      if (exist[i]) {
        // cerr << "round " << beg << " exist idx" << i << '\n'; 
        ++cnt[a[i]]; 
      }
    }
  }
  for (int i = 1; i <= m; ++ i) {
    cout << cnt[i] << ' '; 
  }
  cout << '\n'; 
}
void brute_force2() {
  vector<int> cnt(m + 1, 0); 
  for (int beg = 1; beg <= n; ++ beg) {
    vector<stack<int>> lst(m + 1); 
    vector<int> exist(n + 1, true); 
    vector<int> rm_r(n + 1, -1); // rm_r[l] = r + 1; [ ) 
    for (int i = beg; i <= n; ++ i) {
      if (lst[a[i]].size()) {
        auto tmp = lst[a[i]].top();  // now lst
        for (int j = tmp; j < i; ++ j) {
          // cerr << "111\n"; 
          if (rm_r[j] != -1) {
            // cerr << "Skip" << j << "to" << rm_r[j] << " i: " << i << '\n'; 
            j = rm_r[j]; 
            // cerr << "j=" << j << '\n'; 
            if (j >= i) {
              break; 
            }
          }
          
          exist[j] = false; 
          // if(j==4702) {
            // cerr << exist[j] << '\n'; 
          // }
          // cerr << j << " out! \n"; 
          if (lst[a[j]].size()) {
            lst[a[j]].pop(); 
          }
          // ++j; // 
        }
        rm_r[tmp] = max(rm_r[tmp], i); 
      }
      lst[a[i]].push(i); 
    }
    for (int i = beg; i <= n; ++ i) {
      if (exist[i]) {
        // cerr << "round " << beg << " exist idx" << i << '\n'; 
        ++cnt[a[i]]; 
      }
    }
  }
  for (int i = 1; i <= m; ++ i) {
    cout << cnt[i] << ' '; 
  }
  cout << '\n'; 
}
int main() {
  freopen("card.in", "r", stdin); 
  freopen("card.out", "w", stdout); 
  cin >> n >> m; 
  for (int i = 1; i <= n; ++ i) cin >> a[i]; 
  // fill(nxt + 1, nxt + 1 + n, -1); 
  // fill(lst + 1, lst + 1 + n, -1); 
  // for (int i = 1; i <= n; ++ i) {
  //   if (lst[a[i]] != -1) nxt[lst[a[i]]] = i; 
  //   lst[a[i]] = i; 
  // }
  // vector<pair<int, int>> r; 
  // for (int i = 1; i <= n; ++ i) {
  //   if (nxt[i] != -1) {
  //     r.emplace_back(i, nxt[i] - 1); 
  //   }
  // }
  // sort(r.begin(), r.end()); 
  // auto s = r; 
  bool chkA = true; 
  for (int i = 1; i < n; ++ i) {
    if (a[i] > a[i + 1]) {
      chkA = false; 
      break; 
    }
  }
  if (chkA) { 
    vector<ll> cnt(m + 1, 0);  
    for (int i = 1; i <= n; ++ i) ++cnt[a[i]]; 
    vector<ll> pre(m + 1, 0); 
    for (int i = 1; i <= m; ++ i) {
      pre[i] = pre[i - 1] + cnt[i]; 
      cout << pre[i] << ' '; 
    }
    cout << '\n'; 
    // cout << accumulate(cnt.begin(), cnt.end(), 0);
    return 0; 
  }
  if (n <= 500) brute_force1(); 
  else if (n <= 5000) brute_force2(); 
  else brute_force2(); 
  return 0; 
}