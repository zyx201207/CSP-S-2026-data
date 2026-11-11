#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("migrate.in");
ofstream fout("migrate.out");

const ll kMaxN = 2e6 + 5, kMaxM = 5e3 + 5;
ll c, T, n, m, ans, a[kMaxN], mini[kMaxM][kMaxM], cnt[kMaxM][kMaxM];

void solve1() {
  ll a, b;
  n = m = 0;
  fin >> n >> m >> a >> b, m /= (b - a);
  for(ll i = 3, x; i <= n; i++) {
    fin >> x;
  }
  if(m < 2) fout << "0\n";
  else fout << max(0ll, n - m - m + 1) << '\n';
}

void dfs(ll op) {
  mini[op][op] = 0, cnt[op][op] = 1;
  for(ll x = op; x <= n; x++) {
    for(ll i = x + 1; i <= n; i++) {
      if((abs((__int128_t)a[i] - (__int128_t)a[x])) <= m) {
        if(mini[op][i] > mini[op][x] + 1) {
          mini[op][i] = mini[op][x] + 1, cnt[op][i] = cnt[op][x];
        } else if(mini[op][i] == mini[op][x] + 1) {
          cnt[op][i] += cnt[op][x];
        }
        // cout << op << ' ' << x << ' ' << i << ' ' << mini[op][x] << ' ' << mini[op][i] << ' ' << cnt[op][i] << '\n';
      } else {
        break;
      }
    }
  }
}

void solve2() {
  fin >> n >> m, ans = 0;
  for(ll i = 1; i <= n; i++) {
    fin >> a[i];
  }
  fill(mini[0], mini[0] + kMaxM * kMaxM, 1e18);
  fill(cnt[0], cnt[0] + kMaxM * kMaxM, 0);
  for(ll i = 1; i <= n; i++) {
    dfs(i);
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = i + 1; j <= n; j++) {
      ans += (cnt[i][j] == 2);
      if(cnt[i][j] == 2) {
        // cout << i << ' ' << j << '\n';
      }
    }
  }
  fout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  for(fin >> c >> T; T; T--) {
    if(c == 11 || c == 12) {
      solve1();
    } else {
      solve2();
    }
  }
  return 0;
}
/*
cd /home/noilinux/HN-S01047/migrate/ && ulimit -s 102400 && g++ migrate.cpp -O2 -Wall -o migrate && time ./migrate && diff migrate.out migrate.ans -Bb
*/