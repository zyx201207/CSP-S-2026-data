#include <bits/stdc++.h>
#define int ll
//#define DEBUG
using namespace std;
using ll = long long;

int n, m, arr[500050];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  int cs = 0, l = 1, ans = 0;
  for(int i = 1; i <= n; i++) {
    cs += (arr[i] - arr[i - 1]) * (i - l);
    for(; cs > m; cs -= arr[i] - arr[l++]);
    ans = max(ans, i - l + 1);
  }
  cout << ans << '\n';
  return 0;
}
/*
My Luogu ID:928986
I imdly known the solution and coded this one in 10mins.
*/
