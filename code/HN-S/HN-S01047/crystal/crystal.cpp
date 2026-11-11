#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

const int kMaxN = 5e5 + 5;
ll n, m, ans, a[kMaxN], sum[kMaxN];

bool check(ll x, ll y) {
  return (sum[y - 1] - sum[x - 1] + m >= a[y] * (y - x));
}

ll solve(ll i) {
  ll l = 1, r = i - 1, mid = 0;
  for(; l < r;) {
    mid = (l + r) >> 1;
    if(check(mid, i)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  fin >> n >> m;
  for(int i = 1; i <= n; i++) {
    fin >> a[i];
  }
  sort(a + 1, a + 1 + n), a[0] = a[1] - 1;
  for(int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for(ll i = n, cnt, x; i >= 1; i--) {
    for(cnt = 1; a[i - 1] == a[i] && i > 1; i--, cnt++);
    x = solve(i);
    // cout << i << ' ' << x << '\n';
    ans = max(ans, cnt + i - x);
  }
  fout << ans;
  return 0;
}
/*
cd /home/noilinux/HN-S01047/crystal/ && ulimit -s 102400 && g++ crystal.cpp -O2 -Wall -o crystal && time ./crystal && diff crystal.out crystal.ans -Bb
*/