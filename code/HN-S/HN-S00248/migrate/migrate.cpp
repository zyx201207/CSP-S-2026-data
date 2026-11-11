#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kMaxN = 2e6 + 5;

int n, c, d, T, a[kMaxN], ans[kMaxN], to[kMaxN], cnt[kMaxN], p0[kMaxN], p1[kMaxN], p2[kMaxN];
bool f[kMaxN];

void Init() {
  for(int i = 1; i <= n; i++) {
    ans[i] = to[i] = cnt[i] = f[i] = 0;
  }
}

int Get_ans() {
  cin >> n >> d;
  Init();
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i <= n; i++) {
    p0[i] = p1[i] = p2[i] = 0;
  }
  for(int i = 1; i <= n; i++) {
    int pos = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
    to[i] = min(n, pos);
  }
  int res = 0;
  if(n == 1) {
    return 0;
  }
  if(c >= 11 && c <= 12) {
    if((a[2] - a[1]) * 2 == d) {
      return (n - 2);
    } else {
      return 0;
    }
  } else {
    if(c >= 15 && c <= 18) {
      p0[0] = 1;
      for(int i = 1; i <= n; i++) {
        p0[0]++;
        for(int j = 1; j <= min(i, 10ll); j++) {
          for(; to[p0[j]] < p0[j - 1] && p0[j] <= i; p0[j]++);
          for(; to[p1[j]] <= p0[j - 1] && p1[j] <= i; p1[j]++);
          for(; to[p2[j]] <= p0[j - 1] + 1 && p2[j] <= i; p2[j]++);
          p0[j]--, p1[j]--, p2[j]--;
        }
        bool f = 1;
        for(int j = 1; j <= min(i, 10ll); j++) {
          // cerr << i << " " << j << " " << to[p1[j]] << " " << p0[j - 1] << " " << p0[j] << ' ' << p1[j] << ' ' << p2[j] << '\n';
          if(p0[j] == p1[j]) {
            f = 0;
            int sum = 0;
            for(int k = j; k <= min(i, 10ll); k++) {
              if(p1[k] == p0[k]) {
                break;
              }
              sum += p1[k] - p0[k];
            }
            res += sum;
          }
          if(j > 1) {
            res += p2[j] - p1[j];
          }
          // cerr << i << " " << j << " " << res << '\n';
        }
      }
    } else {
      p0[0] = 1;
      for(int i = 1; i <= n; i++) {
        p0[0]++;
        for(int j = 1; j <= i; j++) {
          for(; to[p0[j]] < p0[j - 1] && p0[j] <= i; p0[j]++);
          for(; to[p1[j]] <= p0[j - 1] && p1[j] <= i; p1[j]++);
          for(; to[p2[j]] <= p0[j - 1] + 1 && p2[j] <= i; p2[j]++);
          p0[j]--, p1[j]--, p2[j]--;
        }
        bool f = 1;
        for(int j = 1; j <= i; j++) {
          // cerr << i << " " << j << " " << to[p1[j]] << " " << p0[j - 1] << " " << p0[j] << ' ' << p1[j] << ' ' << p2[j] << '\n';
          if(p0[j] == p1[j]) {
            f = 0;
            int sum = 0;
            for(int k = j; k <= i; k++) {
              if(p1[k] == p0[k]) {
                break;
              }
              sum += p1[k] - p0[k];
            }
            res += sum;
          }
          if(j > 1) {
            res += p2[j] - p1[j];
          }
          // cerr << i << " " << j << " " << res << '\n';
        }
      }
    }
  }
  return res;
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for(cin >> c >> T; T--; ) {
    cout << Get_ans() << '\n';
  }
  return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

*/