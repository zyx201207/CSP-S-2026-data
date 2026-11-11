#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 5;

int n, ans;
ll m, a[MAXN];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1, j = 1; i <= n; i++) {
    m -= (a[i] - a[i - 1]) * (i - j);
    for (; m < 0; j++) m += a[i] - a[j];
    ans = max(ans, i - j + 1);
  }
  cout << ans;
  return 0;
}