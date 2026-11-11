#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e6 + 5;

int c, t, n, m, k, ans, s, a;
vector<int> e[kMaxN];
bool b[kMaxN];

void S1(int x, int f) {
  s += b[x] && !b[f];
  for (int i : e[x]) {
    if (i != f) {
      S1(i, x);
    }
  }
}

void S2(int x, int f, int d) {
  if (b[x]) {
    a = min(a, d);
  }
  for (int i : e[x]) {
    if (i != f) {
      S2(i, x, d + 1);
    }
  }
}

bool C(int x) {
  int l = x, r = k - x + 1;
  l += m - 2;
  int mi = (l + r) / 2;
  return min(mi - l, r - mi) + 1 <= x;
}

int main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(0) -> sync_with_stdio(0);
  cin >> c >> t;
  if (c == 13 || c == 14) {
    for (; t--;) {
      cin >> n >> m;
      for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
      }
      k = n / 2;
      if (m == n) {
        cout << "0\n";
      } else if (m >= k) {
        cout << "1\n";
      } else {
        int l = 0, r = k + 1;
        for (; l + 1 < r;) {
          int x = l + r >> 1;
          C(x) ? (r = x) : (l = x);
        }
        cout << r << "\n";
      }
    }
    return 0;
  }
  for (; t--;) {
    cin >> n >> m;
    fill(e + 1, e + n + 1, e[0]);
    for (int i = 1, x, y; i < n; i++) {
      cin >> x >> y;
      e[x].push_back(y), e[y].push_back(x);
    }
    ans = 1e9;
    for (int i = 0; i < (1 << n); i++) {
      if (__builtin_popcount(i) != m) continue;
      for (int j = 1; j <= n; j++) {
        b[j] = (i >> j - 1 & 1);
      }
      s = 0;
      S1(1, 0);
      if (s > 2) continue;
      int v = 0;
      for (int j = 1; j <= n; j++) {
        a = 1e9;
        S2(j, 0, 0);
        v = max(v, a);
      }
      ans = min(ans, v);
    }
    cout << ans << "\n";
  }
  return 0;
}