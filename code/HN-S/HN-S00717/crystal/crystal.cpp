#include <iostream>
#include <algorithm> 

using namespace std;
using ll = long long;

void file () {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
}

const int kN = 5e5 + 5;

int n; 
ll m, a[kN], s[kN]; 

ll calc (int l, int r) {
  return (r - l + 1) * a[r] - (s[r] - s[l - 1]);
}

void fakemain () {
  cin >> n >> m; 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; 
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i]; 
  int ans = 0; 
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j < n && calc(i, j + 1) <= m) ++j;
    ans = max(ans, j - i + 1);
  }
  cout << ans << '\n';
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  fakemain();
  return 0; 
}