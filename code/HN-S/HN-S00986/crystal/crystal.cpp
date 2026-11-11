#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define int long long
#define chkmax(x, y) (x = max(x, y))
#define chkmin(x, y) (x = min(x, y))
// #define pb push_back
using namespace std;

const int MAXN = 5e5 + 5;

int n, m, a[MAXN], s[MAXN];

bool check(int j, int i) {
  return (i - j + 1) * a[i] - (s[i] - s[j - 1]) <= m;
}

signed main() {
  freopen("crystal.in", "r", stdin);

  freopen("crystal.out", "w", stdout);
  // freopen("crystal1.in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int ans = 0;
  rep(i, 1, n) s[i] = s[i - 1] + a[i];
  rep(i, 1, n) {
    int tl = 1, tr = i;
    for (;tl < tr;) {
      int mid = (tl + tr >> 1);
      if (check(mid, i)) {
        tr = mid;
      } else {
        tl = mid + 1;
      }
    }
    chkmax(ans, i - tl + 1);
  }
  cout << ans;
  return 0;
}// g++ crystal.cpp -o crystal -std=c++14 -O2 && ./crystal