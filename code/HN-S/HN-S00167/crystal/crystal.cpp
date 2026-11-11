/*
uid:681755
*/
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const LL kMaxN = 5e5 + 1;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

LL n, m, a[kMaxN], s[kMaxN];

int main() {
  fin >> n >> m;
  for (LL i = 1; i <= n; i++) {
    fin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (LL i = 1; i <= n; i++) {
    s[i] = a[i] + s[i - 1];
  }
  LL ans = 0;
  for (LL i = 1; i <= n; i++) {
    LL l = 1, r = i;
    while (l < r) {
      LL m = l + r >> 1;
      if (s[i] - s[m - 1] >= (i - m + 1) * a[i] - ::m) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    ans = max(ans, i - l + 1);
  }
  fout << ans << '\n';
  return 0;
}