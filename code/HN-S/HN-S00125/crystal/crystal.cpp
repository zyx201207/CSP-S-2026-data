/*
finish at 14:41
我的力量无人能及！
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 500005;

int n, ans;
i64 m, a[MAXN], sum[MAXN];

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  for(int i = 1, j = 1; i <= n; ++i) {
    for(; j < i && 1ll * a[i] * (i - j + 1) - sum[i] + sum[j - 1] > m; ++j);
    ans = max(ans, i - j + 1);
  }
  cout << ans << "\n";
  return 0;
}
