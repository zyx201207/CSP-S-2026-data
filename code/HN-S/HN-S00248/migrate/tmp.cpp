#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
using namespace std;
using LL = long long;
using Pii = pair<int, int>;

const int kMaxN = 2e6 + 5;

int n, d, T, a[kMaxN], ans[kMaxN], to[kMaxN], cnt[kMaxN];
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
  LL res = 0;
  for(int i = 1; i <= n; i++) {
    int pos = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
    to[i] = min(n, pos);
    cnt[i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    int pos = to[i];
    if(!to[i]) {
      break;
    }
    if(to[pos] == pos) {

    }
    f[i] = (to[pos] == to[pos - 1]);
    // cerr << i << " " << to[i] << " " << pos << " " << f[i] << '\n';
    if(!f[i]) {
      cnt[to[i]] += cnt[i];
    } else {
      if(to[pos - 2] != to[pos]) {
        cerr << "Zrr\n";
        ans[to[i]]++;
        if(to[pos - 1] - a[i - 1] > d) {
          ans[to[i]] += cnt[i] - 1;
        }
      }
    }
  }
  reverse(a + 1, a + n + 1);
  reverse(ans + 1, ans + n + 1);
  fill(cnt, cnt + n + 1, 0);
  for(int i = 1; i <= n; i++) {
    a[i] = -a[i];
  }
  for(int i = 1; i <= n; i++) {
    int pos = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
    to[i] = min(n, pos);
    cnt[i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    int pos = to[i];
    if(!to[pos] || !to[i]) {
      break;
    }
    f[i] = (to[pos] == to[pos - 1]);
    if(!f[i]) {
      cnt[to[i]] += cnt[i];
    } else {
      if(to[pos - 2] != to[pos]) {
        res += ans[to[i] - 1];
        if(to[pos - 1] - a[i - 1] > d) {
          res += ans[to[i] - 1] * (cnt[i] - 1);
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
  for(cin >> T >> T; T--; ) {
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