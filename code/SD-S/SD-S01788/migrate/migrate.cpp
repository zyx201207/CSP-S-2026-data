#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); i++)
#define of(i, a, b)	for (int i = (a); i >= (b); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ull = unsigned long long;
constexpr int N = 1e6 + 5;
map<pii, pii> buc;
namespace Tau {
  ll x[N], d;
  int n, tag[N];
  vector<pii> Pans;
  void main() {
    buc.clear();
    Pans.clear();
    cin >> n >> d;
    fo(i, 1, n) cin >> x[i];
    fo(i, 1, n) tag[i] = 0;
    int l = 1, r = 1;
    fo(i, 1, n) {
      while (l <= i && x[i] - x[l] > d)  l++;
      while (r < n && x[r + 1] - x[i] <= d)  r++;
      if (buc.count(pii(l, r)) != 0) {
        int Mn, Mx;
        auto &cur = buc[pii(l, r)];
        tie(Mn, Mx) = buc[pii(l, r)];
        cur.first = min<int>(cur.first, i);
        cur.second = max<int>(cur.second, i);
      } else {
        buc[pii(l, r)] = {i, i};
      }
    }
    for (auto Obj : buc) {
      pii Has, LeRi;
      tie(Has, LeRi) = Obj;
      int DbgL, DbgR;
      tie(DbgL, DbgR) = Has;
      int L, R;
      tie(L, R) = LeRi;
      if (L == R)  continue;
      if (R - L == 1) {
        Pans.push_back({L, R});
        tag[L] = tag[R] = 1;
      } else {
        fo(i, L, R) tag[i] = 1;
      }
    }
    ll ans = 0;
    for (auto Obj : Pans) {
      int L, R;
      tie(L, R) = Obj;
      ll i = L - 1, j = R + 1;
      while (i >= 1 && tag[i] == 0 && x[i + 1] - x[i] <= d)
        i--;
      while (j <= n && tag[j] == 0 && x[j] - x[j - 1] <= d)
        j++;
      ans += 1ll * (L - i - 1) * (j - R - 1);
    }
    for (auto Obj : Pans) {
      int l, r;
      tie(l, r) = Obj;
    }
    cout << ans << "\n";
  }
}
int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(nullptr); 
  int c, t;
  cin >> c >> t;
  while (t--) Tau::main();

  return 0;
}
//再见。迷惑行为求给一个 
