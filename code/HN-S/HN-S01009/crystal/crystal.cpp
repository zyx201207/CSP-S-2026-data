#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 5e5 + 5;

int n, m, mx, a[kMaxN], s[kMaxN];

signed main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j <= i && (i - j + 1) * a[i] - s[i] + s[j - 1] > m; j++);
    mx = max(mx, i - j + 1);
  }
  cout << mx << '\n';
  return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined && ./crystal
*/