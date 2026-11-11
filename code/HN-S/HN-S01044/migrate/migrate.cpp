#include <bits/stdc++.h>

using namespace std;
using Pii = pair<int, int>;
using LL = long long;

const int kMaxN = 2e6 + 5;

LL a[kMaxN], pos[kMaxN], n, d, t, c;
int q[kMaxN];
Pii f[kMaxN];

Pii operator+ (Pii x, Pii y) {
  if (x.first != y.first) {
    return x.first < y.first ? x :  y;
  } else {
    return {x.first, min(3, x.second + y.second)};
  }
}

void Calc() {
  cin >> n >> d;
  LL sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if( n == 1) {
    cout << 0 << "\n";
    return;
  }
  for( int i = 1; i <= n; i++) {
    pos[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
  }
  if (c <= 10) {
    for (int i = 1; i <= n; i++) {
      f[i] = {0, 1};
      int l = 1, r = 0;
      q[++r] = i;
      for (int j = i + 1; j <= n; j++) {
        f[j] = {n + 1, 0};
        for (; l <= r && a[j] - a[q[l]] > d; l++) {
        }
        (l <= r) && (f[j] = f[q[l]], 1);
        for (int k = l + 1; k <= min(r, l + 3); k++) {
          (f[q[k]].first == f[j].first) && (f[j].second = min(3, f[j].second + f[q[k]].second));
        }
        f[j].first++;
        for (; l <= r && f[q[r]].first > f[j].first; r--) {
        }
        q[++r] = j;
        sum += f[j].second == 2;
      }
    }
  }
  cout << sum << "\n";
}

void Init() {

}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> c >> t; t; t--) {
    Calc();
    Init();
  }
  return 0;
}
// g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall && ./migrate