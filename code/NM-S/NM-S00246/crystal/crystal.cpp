#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5 + 10;
int a[MAXN];
int n, m;

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);

  int sum = a[1], l = 1, maxlen = 0;
  for (int i = 2; i <= n; i++) {
    while ((i - l) * a[i] - sum > m && l < i) sum -= a[l++];
    int len = i - l + 1;
    if (len >= maxlen) maxlen = len;
    sum += a[i];
  }

  cout << maxlen;

  return 0;
}