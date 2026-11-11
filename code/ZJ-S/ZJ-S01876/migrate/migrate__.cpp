#include<bits/stdc++.h>

#define Cerr cerr <<
#define Cout cout <<
#define W << ' ' <<
#define Endl << '\n'
#define Back(chk) << " \n"[!!(chk)]

using namespace std;

namespace akitsuki {
  using ll = long long;
  const ll inf = 1e17;
  const int N = 2e6 + 6;
  ll a[N]; int nxt[N], pre[N];
  int cn[N], cp[N], pp[N], nn[N];
  int main() {
    int c, T; cin >> c >> T;
    while(T--) {
      int n; ll d; cin >> n >> d;
      for(int i = 1; i <= n; i++)
        cin >> a[i];
      ll ans = 0;
      int r = 1;
      for(int l = 1; l <= n; l++) {
        while(r <= n && a[r] - a[l] <= d) ++r;
        nxt[l] = r - 1;
        // Cout nxt[l] Back(l == n);
      }
      fill(pre + 1, pre + n + 1, 0);
      for(int i = n; i >= 1; i--)
        if(nxt[i] <= nxt[i - 1]) nxt[i] = 0;
        else pre[nxt[i]] = i;
      fill(cn + 1, cn + n + 1, 0);
      fill(cp + 1, cp + n + 1, 0);
      pp[1] = 1;
      for(int i = 2; i <= n; i++)
        if(pre[i]) pp[i] = i;
        else pp[i] = pp[i - 1];
      nn[n] = n;
      for(int i = n - 1; i >= 1; i--)
        if(nxt[i]) nn[i] = i;
        else nn[i] = nn[i + 1];
      for(int i = n; i >= 1; i--)
        if(nxt[i]) cn[i] += cn[nxt[i]] + (nxt[i] - pp[nxt[i] - 1]);
        else cn[i] = 0;
      for(int i = 1; i <= n; i++)
        if(pre[i]) cp[i] += cp[pre[i]] + (nn[pre[i] + 1] - pre[i]);
        else cp[i] = 0;
      for(int i = 2; i + 1 <= n - 1; i++)
        if(pre[i + 1] && nxt[i] && pre[i + 1] != i)
          ans += cn[i] * 1ll * cp[i + 1];
      Cout ans Endl;
    }
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
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  #endif
  akitsuki :: main();
  return 0;
}
// g++ -o o migrate.cpp -O2 -std=c++14 -static -DLOCAL -Wall
// 16:34