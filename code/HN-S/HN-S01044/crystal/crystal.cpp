#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 5e5 + 5;

LL a[kMaxN], s[kMaxN], n, m;

bool Check(int x) {
  for (int i = 1; i + x - 1 <= n; i++) {
    if (a[i + x - 1] * x - (s[i + x - 1] - s[i - 1]) <= m) {
      return 1;
    }
  }
  return 0;
}

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int l = 0, r = n;
  for (int mid; l < r; Check(mid) ? l = mid : r = mid - 1) {
    mid = l + r + 1 >> 1;
  }
  cout << l;
  return 0;
}
// g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall && ./crystal