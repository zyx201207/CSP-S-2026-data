#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l), i##END = (r); i <= i##END; ++ i)
#define dwn(i, l, r) for (int i = (l), i##END = (r); i >= i##END; -- i)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std; typedef long long i64;

namespace Crystal{
  const int N = 5e5 + 5;
  int n; i64 m, a[N], s[N];
  void main(){
    cin >> n >> m; s[0] = 0;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int l = 1, r = 1; r <= n; ++ r){
      while (l <= r && a[r] * (r - l + 1) - (s[r] - s[l - 1]) > m)
        ++ l;
      // cout << r << ' ' << l << '\n';
      ans = max(ans, r - l + 1);
    }
    cout << ans;
  }
}

int main(){
  File("crystal");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  Crystal::main(); return 0;
}