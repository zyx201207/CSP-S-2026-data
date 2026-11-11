#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e6 + 7, INF = 1e18;
int id;
int n, d, ans;
int a[N];
int f[N], g[N];
// 到 i 的最短路，方案数 
signed Luogu_UID_947527() {
  cin >> n >> d;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }
  ans = 0;
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  if (id == 11 || id == 12) {
    d /= a[2] - a[1];
    if (d <= 1) {
      cout << 0 << '\n';
      return 0;
    }
    cout << max(0ll, n - d * 2 + 1) << '\n';
    return 0;
  }
  if (id == 13 || id == 14) {
    int R = 0;
    for (int i = 1; i <= n; ++ i) {
      if (a[i] - a[1] > d) {
        break;
      }
      R = i;
    }
    int l = 1;
    for (int i = R + 1; i <= n; ++ i) {
      while (a[i] - a[l] > d){
        ++ l;
      }
      ans += R - l + 1 == 2;
    }
    int L = 0;
    for (int i = n; i; -- i) {
      if (a[n] - a[i] > d) {
        break;
      }
      L = i;
    }
    int r = n;
    for (int i = L - 1; i; -- i) {
      while (a[r] - a[i] > d){
        -- r;
      }
      ans += r - L + 1 == 2;
    }
    cout << ans << '\n';
    return 0;
  }
  for (int s = 1; s <= n; ++ s) {
    f[s] = 0;
    g[s] = 1;
    int sum = 1, tmp = 0, l = s;
    for (int i = s + 1; i <= n; ++ i) {
      while (a[i] - a[l] > d) {
        sum -= g[l ++];
        if (!sum) {
          swap(sum, tmp);
        }
      }
      if (l == i) {
        break;
      }
      f[i] = f[l] + 1;
      g[i] = sum;
      ans += g[i] == 2;
      tmp += g[i];
    }
  } 
  cout << ans << endl;
  return 0;
}
signed main() {
//  system("fc migrate.out migrate.ans");
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> id >> T;
  while (T --) {
    Luogu_UID_947527();
  }
  return 0;
}

