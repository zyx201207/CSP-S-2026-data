#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define dF(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using i64 = long long;
const int N = 5e5 + 5;

int n, ans; i64 m, a[N], s[N];

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m, ans = 1;
  F(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  F(i, 1, n) s[i] = s[i - 1] + a[i];
  F(i, 1, n) {
    int l = 1, r = i, mid, p = i;
    while (l <= r) {
      mid = l + r >> 1;
      if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) p = mid, r = mid - 1;
      else l = mid + 1;
    }
    ans = max(ans, i - p + 1);
  }
  cout << ans << "\n";
  return 0;
}