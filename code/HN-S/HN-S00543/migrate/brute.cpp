#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOCAL_IO
#include <iostream>
#else
#include <fstream>

const string kFILE = "migrate";
ifstream cin(kFILE + ".in");
ofstream cout(kFILE + ".ans");
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
      vector<int> v0(n), v1(n);
      v0[i] = v1[i] = 1;
      for (int j = i - 1; j >= 0; --j) {
        v0[j] = (pr[j] <= i && v1[pr[j]]);
        v1[j] = (v0[j] && pl[pr[j]] == j);
      }
      for (int j = i + 1; j < n; ++j) {
        v0[j] = (pl[j] >= i && v1[pl[j]]);
        v1[j] = (v0[j] && pr[pl[j]] == j);
      }
      // cerr << i << ": ";
      // for (int j = 0; j < n; ++j) {
      //   cerr << v0[j] << ' ';
      // }
      // cerr << endl;
      for (int j = 0; j <= i; ++j) {
        f[i] += v0[j];
      }
      for (int j = i; j < n; ++j) {
        g[i] += v0[j];
      }
      // cerr << i << ' ' << f[i] << ' ' << g[i] << endl;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (i < pl[j] && pl[j] + 1 == pr[i]) {
          // cerr << i << ' ' << j << ' ' << f[i] << '*' << g[j] << endl;
          ans += (ll)(pl[pl[j]] == i ? f[i] : 1) * (pr[pr[i]] == j ? g[j] : 1);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}