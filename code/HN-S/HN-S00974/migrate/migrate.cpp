#include <iostream>
using namespace std;
const int maxn = 2000010;
using ll = long long;
int n;
ll ans;
ll d, a[maxn], f[maxn], g[maxn];
int rr, T, p[maxn], q[maxn];

namespace RR {
  pair <int, int> f[5010][5100];
  ll solve () {
    ll sum = 0;
    for (int st = 1; st <= n; st++) {
      f[st][st] = {0, 1};
      for (int j = st + 1; j <= n; j++) f[st][j] = {1e9, 0};
      for (int j = st; j <= n; j++) {
        for (int k = j + 1; k <= n; k++) {
          if (a[k] - a[j] > d) break;
          if (f[st][k].first > f[st][j].first + 1)
            f[st][k] = {f[st][j].first + 1, f[st][j].second};
          else if (f[st][k].first == f[st][j].first + 1)
            f[st][k].second += f[st][j].second;
        }
        if (f[st][j].second == 2) {
          sum++;
        }
      }
    }
    return sum;
  }
};

int main () {
  freopen ("migrate.in", "r", stdin);
  freopen ("migrate.out", "w", stdout);
  cin.tie (0)->sync_with_stdio (false);
  cin >> rr >> T;

  // d = 2e18;
  // cerr << d << endl;
  int cnt = 0;
  while (T--) {
      ++ cnt;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      p[i] = q[i] = f[i] = g[i] = 0; 
    }
    ans = 0;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1];
      while (p[i] < n && a[p[i] + 1] - a[i] <= d) p[i] ++;
      // cout << p[i] << ' ';
    }
    // cout << endl;
    RR::solve ();
    for (int i = 1; i <= n; i++) {
      f[i]++;
      int sum = 0;
      for (int j = 1; j <= i; j++) sum += RR::f[j][i].second == 1;
      if (p[i - 1] == p[i]) f[i] = 1;
      if (p[i] == i) continue;

      // for (int j = max (i + 1, p[i - 1] + 1); j <= p[i]; j++)
        f[p[i]] += f[i];
      // cout << f[i] << ' ' << sum << endl;;f
    }
    // cout << endl;

    q[n + 1] = n;


    // if (cnt == 1) {
    //   for (int i = 1; i <=6; i ++) cout << p[i] << ' ';
    //   cout << endl;
    // }

    for (int i = n; i >= 1; i--) {
      q[i] = q[i + 1];
      while (q[i] > 1 && a[i] - a[q[i] - 1] <= d) q[i] --;
    }
    for (int i = n; i >= 1; i--) {
      g[i]++;
      if (q[i + 1] == p[i]) g[i] = 1;
      if (q[i] == i) continue;
      // for (int j = min (i - 1, q[i + 1] - 1); j >= q[i]; j--)
        g[q[i]] += g[i];
    }


    for (int i = 1; i < n; i++) {
      if (p[i] == i || p[p[i]] == p[i]) continue;
      ll lv = f[i];
      if (p[i - 1] >= p[i] - 1) lv = 1;
      if (p[p[i] - 1] == p[i]) continue;
      int l = p[i];
      if (p[i] - 2 > i) l = max (l, p[p[i] - 2]);
      ll res = 0;
      if (p[p[i] - 1] == p[p[i]] && (p[p[i]] > l)) {
        res = res + lv * (p[p[i]] - 1 - l);
        res = res + lv * g[p[p[i]]];
      } else {
        res = res + lv * (p[p[i] - 1] - l);
      }


        ans += res;
    }
    if (n <= 5000) {
      cout << RR::solve ()<< '\n';
      continue;
    }
    cout << ans << '\n';

  }
  return 0;
}