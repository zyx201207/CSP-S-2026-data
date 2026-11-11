#include <fstream>
#include <algorithm>

using namespace std;
using LL = long long;

const LL kMaxN = 5e5 + 5;

ifstream cin("crystal.in");
ofstream cout("crystal.out");

LL a[kMaxN], p[kMaxN], n, m, ans;

int main() {
  cin >> n >> m;
  for (LL i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (LL i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i];
  }
  for (LL i = 1; i <= n; i++) {
    LL tar = i;
    for (LL l = 1, r = i; l <= r; ) {
      LL mid = (l + r) / 2;
      if ((i - mid + 1) * a[i] - (p[i] - p[mid - 1]) <= m) {
        tar = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ans = max(ans, i - tar + 1);
  }
  cout << ans << '\n';
  return 0;
}