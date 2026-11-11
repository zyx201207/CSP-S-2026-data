#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e6 + 5;

int tid, T, n, d, a[kMaxN], R[kMaxN], c[kMaxN];

signed main() {
  freopen("migrate3.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> tid >> T; T--;) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      int p = upper_bound(a + 1, a + n + 1, a[i] + d) - a;
      R[i] = p - 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = R[i];
      int lst = i;
      fill(c + i, c + n + 1, 0);
      for (int j = i; j <= x; j++) c[j] = 1;
      for (; x <= n && R[x] != x; x = R[x]) {
        if (c[x] == 1) {
          if (lst + 1 == x) {
            fill(c + x + 1, c + R[x] + 1, 1);
          } else if (c[x - 1] > 1) {
            fill(c + x + 1, c + R[x - 1] + 1, 3);
            fill(c + R[x - 1] + 1, c + R[x] + 1, 1);
          } else {
            int p = (lst + 2 == x ? x : R[x - 2]);
            fill(c + x + 1, c + p + 1, 3);
            fill(c + p + 1, c + R[x - 1] + 1, 2);
            fill(c + R[x - 1] + 1, c + R[x] + 1, 1);
          }
        } else if (c[x] == 2) {
          int p = (lst + 1 == x ? x : R[x - 1]);
          fill(c + x + 1, c + p + 1, 3);
          fill(c + p + 1, c + R[x] + 1, 2);
        } else {
          break;
        }
        lst = x;
      }
      for (int j = i; j <= n; j++) ans += (c[j] == 2);
    }
    cout << ans << '\n';
  }
}
/*
g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined && ./migrate

0 1
5 3
-2 -1 0 1 2

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 2e6 + 5, kC = 4;

int tid, T, n, d, a[kMaxN], R[kMaxN], c[kMaxN], f[kMaxN];
vector<int> e[kMaxN];
int s[kMaxN][kC];

/*
0: 1 1
1: x 1
2: x 2
3: x x

x=>2
*/

void S(int x, int fa) {
  if (x == 1) return;
  f[x] = 1;
  // if (x + 1 == fa) {
  //   s[x][0] = s[x][1] = s[fa][0];
  //   s[x][2] = s[fa][2] + fa - x;
  //   s[x][3] = s[fa][3];
  // } else if (x + 2 == fa) {
  //   { // 0
  //     cout << x << ' ' << fa << '\n';
  //     int st = -1;
  //     if (R[x - 1] == fa) st = 2;
  //     else if (R[x - 1] + 1 == fa) st = 1;
  //     else st = 0;
  //     s[x][0] = s[fa][st] + R[x - 1] - x;
  //   }
  //   { // 1
  //     int st = -1;
  //     if (R[x - 1] == fa) st = 3;
  //     else if (R[x - 1] + 1 == fa) st = 1;
  //     else st = 0;
  //     s[x][1] = s[fa][st];
  //   }
  //   { // 2
  //     int st = -1;
  //     if (R[x - 1] == fa) st = 3;
  //     else st = 2;
  //     s[x][2] = s[fa][st] + fa - R[x - 1];
  //   }
  //   { // 3
  //     s[x][3] = s[fa][3];
  //   }
  // } else {
    if (R[x - 2] != R[x - 1]) { // 0
      int st = -1;
      if (fa == R[x - 1]) st = 2;
      else if (fa == R[x - 1] + 1) st = 1;
      else st = 0;
      s[x][0] = s[fa][st] + R[x - 1] - R[x - 2];
    } else {
      int st = -1;
      if (R[x - 2] == fa) st = 3;
      else if (fa == R[x - 1] + 1) st = 1;
      else st = 0;
      s[x][0] = s[fa][st] + R[x - 1] - R[x - 2];
    }
    { // 1
      int st = -1;
      if (R[x - 1] == fa) st = 3;
      else if (R[x - 1] + 1 == fa) st = 1;
      else st = 0;
      s[x][1] = s[fa][st];
    }
    { // 2
      int st = -1;
      if (R[x - 1] == fa) st = 3;
      else st = 2;
      s[x][2] = s[fa][st] + fa - R[x - 1];
    }
    { // 3
      s[x][3] = s[fa][3];
    }
  // }
  for (int nxt : e[x]) {
    if (nxt != fa) {
      S(nxt, x);
    }
  }
}

signed main() {
  // freopen("migrate.in", "r", stdin);
  // freopen("migrate.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> tid >> T; T--;) {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      e[i].clear();
      f[i] = 0;
      s[i][0] = s[i][1] = s[i][2] = s[i][3] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int p = upper_bound(a + 1, a + n + 1, a[i] + d) - a;
      R[i] = p - 1;
      e[R[i]].push_back(i);
    }
    for (int i = n; i; i--) {
      if (!f[i]) S(i, 0);
    }
    // S(n, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += s[R[i]][0];
    }
    cout << ans << '\n';
  }
}
/*
g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined && ./migrate

0 1
5 3
-2 -1 0 1 2

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

0 1
4 2
1 2 3 4

*/