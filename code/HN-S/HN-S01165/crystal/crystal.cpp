#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 5e5 + 1;

int n;
LL m, a[kN], sum[kN];
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)  cin >> a[i];
  sort(a + 1, a + n + 1);
  int Ans = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
    int l = 1, r = i, ans = i;
    for (int mid; l <= r;) {
      mid = (l + r) / 2;
      if ((i - mid + 1ll) * a[i] - (sum[i] - sum[mid - 1]) <= m)  r = mid - 1, ans = mid;
      else  l = mid + 1;
    }
    Ans = max(Ans, i - ans + 1);
  }
  cout << Ans << '\n';
  return 0;
}