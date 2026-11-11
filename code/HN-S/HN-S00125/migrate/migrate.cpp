/*
u -> v 每次跳最远 与 v -> u 每次跳最远 路径差1
*/
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MAXN = 2000005;

int n;
i64 D, a[MAXN];

namespace sub {
  int dis[MAXN << 1], cnt[MAXN << 1], R[MAXN];
  vector<int> e[2 * MAXN];
  bool flag[MAXN << 1];

  void Solve(int _C) {
    cin >> n >> D;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for(int i = 1, j = 1; i <= n; ++i) {
      for(; j < n && a[j + 1] - a[i] <= D; ++j);
      R[i] = j;
    }
    int ans = 0;
    for(int s = 1; s <= n; ++s) {
      for(int i = s; i <= n; ++i) dis[i] = 1e9, cnt[i] = flag[i] = 0;
      dis[s] = 0, cnt[s] = 1;
      for(int i = s; i <= n; ++i) {
        ans += (cnt[i] == 2);
        for(int j = R[i]; j > i && dis[j] >= dis[i] + 1; --j) {
          if(dis[j] > dis[i] + 1) dis[j] = dis[i] + 1, cnt[j] = cnt[i];
          else cnt[j] = min(3, cnt[i] + cnt[j]);
        }
      }
    }
    cout << ans << '\n';
  }

}

namespace subA {
  void Solve() {
    cin >> n >> D;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    if(n == 1) {
      cout << "0\n";
      return;
    }
    i64 d = a[2] - a[1];
    if(2 * d > D || d >= D) {
      cout << "0\n";
      return;
    }else {
      i64 x = D / d;
      cout << max(0ll, n - 2 * x + 1) << "\n";
    }
  }
}
/*
namespace subB {
  int check(int i, int j, int k) {
    return k >= 1 && k <= n && a[k] - a[i] <= D && a[j] - a[k] <= D;
  }
  void Solve() {
    cin >> n >> D;
    for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int p = 0;
    i64 ans = 0;
    for(int i = 1; i <= n; ++i) {
      if(a[i] - a[1] <= D && a[n] - a[i] <= D) {
        p = i;
      }
    }
    for(int i = 1, j = 1; i <= n && j <= n; ++i) {
      for(; j <= n && a[j] - a[i] <= D; ++j);
      if(j > n) break;
      int cnt = check(i, j, p - 2) + check(i, j, p - 1) + check(i, j, p) + check(i, j, p + 1) + check(i, j, p + 2);
      if(cnt == 2)
    }
  }
}
*/
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  int _C, _T;
  for(cin >> _C >> _T; _T--; ) {
    if(_C == 11 || _C == 12) subA::Solve();
    //else if(_C == 13 || _C == 14) subB:Solve();
    else sub::Solve(_C);
  }
  return 0;
}
