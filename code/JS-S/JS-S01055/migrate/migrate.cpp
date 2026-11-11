#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;

template<typename T> void check(const T&(*func)(const T&, const T&), T& a, const T& b){ a = func(a, b); }
template<typename T> bool getbit(T x, i32 b){ return (x >> b) & 1; }

void solve(){
  i32 n; i64 d;
  std::cin >> n >> d;
  std::vector<i64> a(n);
  for(auto& x : a){ std::cin >> x; }

  std::vector<i32> nxt(n), prv(n);
  for(i32 i = 0; i < n; i++){
    nxt[i] = i == 0 ? 0 : nxt[i - 1];
    while(nxt[i] + 1 < n and a[nxt[i] + 1] <= a[i] + d){ nxt[i]++; }
    // std::cerr << nxt[i] << "\n";
  }
  std::vector<std::vector<i32> > ele(n);
  for(i32 i = n - 1; i >= 0; i--){
    prv[i] = i == n - 1 ? n - 1 : prv[i + 1];
    while(prv[i] - 1 >= 0 and a[prv[i] - 1] >= a[i] - d){ prv[i]--; }
    // std::cerr << prv[i] << "\n";
    ele[prv[i]].push_back(i);
    if(prv[i] + 1 < n) ele[prv[i] + 1].push_back(i);
  }
  i64 ans = 0;
  std::vector<std::array<i64, 2> > dp(n, {0, 0});
  std::vector<std::array<i64, 2> > pre(n + 1, {0, 0});
  for(i32 i = 0; i < n; i++){
    if(nxt[i] != i){
      if(prv[nxt[nxt[i]]] == nxt[i]){
        dp[nxt[i]][0] += dp[i][0];
        dp[nxt[i]][0] += 1;
        dp[nxt[i]][1] += dp[i][1];
      } else if(prv[nxt[nxt[i]]] == nxt[i] - 1){
        if(nxt[i] - 1 >= 0 and prv[nxt[i] - 1] == i) dp[nxt[i]][1] += dp[i][0];
        dp[nxt[i]][1] += 1;
      }
    }

    for(auto j : ele[nxt[i]]) if(j > nxt[i]) {
      if(prv[j] == nxt[i]){
        ans += dp[i][1];
      } else if(prv[j] == nxt[i] - 1){
        ans += 1;
        if(nxt[i] - 1 >= 0 and prv[nxt[i] - 1] == i) ans += dp[i][0];
      }
    }
    dp[i][0] += 1;
  }
  std::cout << ans << "\n";
}

void open_file(std::string file){
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}

int main(){
  open_file("migrate");

	std::ios::sync_with_stdio(0); std::cin.tie(0);

	i32 c, T = 1;
	std::cin >> c >> T;
  for(i32 i = 0; i < T; i++){ solve(); }

	return 0;
}