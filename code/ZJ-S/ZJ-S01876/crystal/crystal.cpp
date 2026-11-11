#include<bits/stdc++.h>

#define Cerr cerr <<
#define Cout cout <<
#define W << ' ' <<
#define Endl << '\n'
#define Back(chk) << " \n"[!!(chk)]

using namespace std;

namespace akitsuki {
  const int N = 5e5 + 5;
  using ll = long long;
  ll a[N];
  int main() {
    int n; ll m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1, ans = 1;
    for(int i = 1; i <= n; i++) {
      m -= (i - j) * 1ll * (a[i] - a[i - 1]);
      while(m < 0)
        m += (a[i] - a[j]), ++j;
      ans = max(ans, i - j + 1);
    }
    Cout ans Endl;
    return 0;
  }
}
signed main(signed argc, char*argv[]) {
  #ifdef LOCAL
  if(argc >= 3) {
    cin.tie(0) -> sync_with_stdio(0);
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
  }
  #else
  cin.tie(0) -> sync_with_stdio(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  #endif
  akitsuki :: main();
  return 0;
}
// g++ -o o crystal.cpp -O2 -std=c++14 -static -DLOCAL -Wall
// 14:44 pp