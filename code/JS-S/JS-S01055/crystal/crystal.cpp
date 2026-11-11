#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;

template<typename T> void check(const T&(*func)(const T&, const T&), T& a, const T& b){ a = func(a, b); }
template<typename T> bool getbit(T x, i32 b){ return (x >> b) & 1; }

void solve(){
  i32 n; i64 m;
  std::cin >> n >> m;
  std::vector<i32> a(n); for(auto& x : a){ std::cin >> x; }

  std::sort(a.begin(), a.end());

  std::vector<i64> pre(n + 1);
  for(i32 i = 0; i < n; i++){ pre[i + 1] = pre[i] + a[i]; }

  auto check = [&](i32 num) -> bool {
    for(i32 i = 0; i + num <= n; i++){
      i64 sum = (i64)a[i + num - 1] * num - (pre[i + num] - pre[i]);
      if(sum <= m) return true;
    }
    return false;
  };

  i32 L = 0, R = n + 1;
  while(L + 1 < R){
    i32 mid = (L + R) / 2;
    if(check(mid)){
      L = mid;
    } else {
      R = mid;
    }
  }
  std::cout << L << "\n";
}

void open_file(std::string file){
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}

int main(){
  open_file("crystal");
	std::ios::sync_with_stdio(0); std::cin.tie(0);

	i32 T = 1;
	// std::cin >> T;
  for(i32 i = 0; i < T; i++){ solve(); }

	return 0;
}