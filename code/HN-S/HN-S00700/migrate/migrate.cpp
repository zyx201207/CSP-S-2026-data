#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e6 + 5;

ll n, d, a[N], lx[N], rx[N];

ll L[N], R[N];

vector<ll> v[N], nbr[N];

void solve() {
  cin >> n >> d;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i <= n + 1; i++) {
    v[i].clear(), nbr[i].clear();
    L[i] = R[i] = lx[i] = rx[i] = 0;
  }
  for (ll i = 1, j = 1; i <= n; i++) {
    for (; j + 1 <= n && a[j + 1] - a[i] <= d; j++) {
    }
    rx[i] = j;
    v[j].push_back(i);
  }
  for (ll i = n, j = n; i; i--) {
    for (; j - 1 >= 1 && a[i] - a[j - 1] <= d; j--) {
    }
    lx[i] = j; 
    nbr[j].push_back(i);
  }
  for (ll i = n; i; i--) {
    if (rx[i] == rx[i - 1] || i == 1) {
      R[i] = 0;
    } else {
      R[i] += rx[i] - rx[i - 1];
      for (ll x : v[i]) {
        R[x] += R[i];
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (lx[i] == lx[i + 1] || i == n) {
      L[i] = 0;
    } else {
      L[i] += lx[i + 1] - lx[i];
      for (ll x : nbr[i]) {
        L[x] += L[i];
      }
    }
  }
  ll ans = 0;
  for (ll i = 2; i + 1 < n; i++) {
    if (lx[i + 1] < i && rx[i] > i + 1) {
      ll cnt = 0, tmp = 0;
      if (lx[i + 1] == lx[i]) {
        cnt = L[i + 1];
      } else {
        cnt = lx[i + 2] - lx[i + 1];
      }
      if (rx[i + 1] == rx[i]) {
        tmp = R[i];
      } else {
        tmp = rx[i] - rx[i - 1];
      }
      ans += 1ll * cnt * tmp;
    }
    // cout << lx[i] << " " << rx[i + 1] << " " << L[i + 1] << " " << R[i] << "\n";
  }
  // for (ll i = 2; i + 1 < n; i++) {
  //   if (lx[i] == lx[i + 1] && rx[i] == rx[i + 1]) {
  //     ll x = lx[i], y = rx[i];
  //     if (a[y] - a[i - 1] > d && a[i + 2] - a[x] > d) {
  //       ans += 1ll * (L[x] + 1) * (R[y] + 1);
  //     }
  //   }
  // }
  // for (ll i = 1; i + 1 < n; i++) {
  //   ll x = rx[i];
  //   if (rx[x - 1] == rx[x - 2]) {
  //     continue;
  //   }
  //   ll cnt = rx[x - 1] - rx[x - 2];
  //   ans += cnt;
  //   if (rx[x - 1] != rx[x]) {
  //     continue;
  //   }
  //   if (lx[x - 1] == lx[x] && lx[x - 1] == i) {
  //     ans--;
  //     continue;
  //   }
  //   ans += R[x];
  // }
  cout << ans << "\n";
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ll c, T;
  cin >> c >> T;
  for (ll i = 1; i <= T; ) {
    solve();
    i++;
  }
  return 0;
}

/*
这道题我开场1个半小时就会了，结果我犯了个错误，调了两个小时，结束前40分钟才调完，我已机库

其实我暗恋水深姐姐1年半了水深哥哥太帅了
*/