#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFILE = "migrate";
ifstream cin(kFILE + ".in");
ofstream cout(kFILE + ".out");
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  using ll = long long;

  int tid, tt;
  for (cin >> tid >> tt; tt--; ) {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> a(n);
    for (ll &i : a) {
      cin >> i;
    }
    vector<int> pl(n), pr(n);
    for (int i = 0; i < n; ++i) {
      pl[i] = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin();
      pr[i] = upper_bound(a.begin(), a.end(), a[i] + d) - a.begin() - 1;
      // cerr << i << ' ' << pl[i] << ' ' << pr[i] << endl;
    }
    vector<int> f(n), g(n);
    for (int i = 0; i < n; ++i) {
      if (pl[i] < i && pr[pl[i]] == i) {
        f[i] += f[pl[i]];
      }
      ++f[i];
      if (pr[i] > i && pl[pr[i]] != i) {
        ++f[pr[i]];
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (pr[i] > i && pl[pr[i]] == i) {
        g[i] += g[pr[i]];
      }
      ++g[i];
      if (pl[i] < i && pr[pl[i]] != i) {
        ++g[pl[i]];
      }
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      if (i < pr[i] - 1) {
        ++c[pr[i] - 1];
      }
    }
    ll ans = 0;
    for (int j = 0; j < n; ++j) {
      ans += c[pl[j]];
    }
    for (int i = 0; i < n; ++i) {
      int j = pr[pr[i]];
      if (i < pl[j] && pl[j] + 1 == pr[i]) {
        if (pl[pl[j]] == i) {
          ans += (ll)f[i] * g[j] - 1;
        } else {
          ans += g[j] - 1;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      int i = pl[pl[j]];
      if (i < pl[j] && pl[j] + 1 == pr[i] && pr[pr[i]] != j) {
        ans += f[i] - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}