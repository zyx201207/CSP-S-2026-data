#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); i++)
#define of(i, a, b)	for (int i = (a); i >= (b); i++)
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
int n, m;
ll a[N];
int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> m;
  fo(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  ll ans = 1, j = 1, cur = 0;
  fo(i, 2, n) {
    ll cnt = i - j + 1, delt = a[i] - a[i - 1];
    cur += delt * (cnt - 1);
    while (j <= i && cur > m) {
      cur -= a[i] - a[j];
      j++;
    }
    ans = max<ll>(ans, i - j + 1);
  }
  cout << ans;
}
