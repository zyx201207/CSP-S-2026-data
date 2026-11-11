#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 2e5 + 1;

ifstream fin("brute.in");
ofstream fout("brute.out");

LL n, m, a[kMaxN], s[kMaxN];

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = a[i] + s[i - 1];
  }
  LL ans = 0;
  for (LL i = 1; i <= n; i++) {
    for (LL j = 1; j <= i; j++) {
      if (m >= (i - j + 1) * a[i] - (s[i] - s[j - 1])) {
        ans = max(ans, i - j + 1);
      }
    }
  }
  fout << ans << '\n';
  return 0;
}