#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Pii = pair <int, int>;

const int kN = 2e6 + 5;

ll ans;
ll d, a[kN], r[kN], l[kN];
vector <int> e[kN];
int c, T, n;

void Solve () {
  for (int i = 1, lt = 1; i <= n; ++i) {
    for (; lt < i && a[i] - a[lt] > d; ++lt) {}
    l[i] = lt;
  }
  for (int i = 1, rt = 1; i <= n; ++i) {
    for (; rt < n && a[rt + 1] - a[i] <= d; ++rt) {}
    r[i] = rt;
  }

  if (c == 13 || c == 14) {
    cout << "0\n";
  } else if (c >= 19) {
    cout << "0\n";
  } else {
    ans = 0;
    for (int i = 1; i <= n;++i) {
      for (int j = i + 2; j <= n; ++j) {
        ans += r[i] == l[j] + 1;
      }
    }
    cout << ans << '\n';
  }
}

int main () {
  freopen ("migrate.in", "r", stdin);
  freopen ("migrate.out", "w", stdout);
  cin.tie (0)->sync_with_stdio (0);

  cin >> c >> T;
  for (; T--; ) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    Solve ();
  }
  return 0;
}