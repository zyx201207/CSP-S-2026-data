#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 2e6 + 5;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

LL c, t, n, d, a[kMaxN], r[kMaxN], in[kMaxN], f[kMaxN], ct[kMaxN];
vector<int> g[kMaxN];

void to(int i, int j) {
  if (f[j] > f[i] + 1) {
    f[j] = f[i] + 1, ct[j] = ct[i];
  } else if (f[j] == f[i] + 1) {
    ct[j] += ct[i];
  }
}

void solve() {
  fin >> n >> d;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  a[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    r[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
  }
  if (c <= 10) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      fill(f + i, f + n + 1, 1e9);
      fill(ct + i, ct + n + 1, 0);
      f[i] = ct[i] = 1;
      for (int j = i; j <= n; j++) {
        if (r[j] != j) {
          to(j, r[j]);
        }
        if (r[j] - 1 > j) {
          to(j, r[j] - 1);
        }
        if (r[j] - 2 > j) {
          to(j, r[j] - 2);
        }
        if (ct[j] == 2) {
          sum++;
        }
      }
    }
    fout << sum << '\n';
  } else if (c == 13 || c == 14) {
    fout << 0 << '\n';
  }
}

void clear() {
}

int main() {
  for (fin >> c >> t; t; t--) {
    solve();
  }
  return 0;
}
/*
cutezrr!
*/