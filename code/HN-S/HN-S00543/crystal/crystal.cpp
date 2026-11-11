#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFILE = "crystal";
ifstream cin(kFILE + ".in");
ofstream cout(kFILE + ".out");
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  using ll = long long;
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);
  for (ll &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  ll s = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    s += a[i];
    for (; a[i] * (i - j + 1) - s > m; s -= a[j++]) {
    }
    ans = max(ans, i - j + 1);
  }
  cout << ans << '\n';
  return 0;
}