#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

ll n, m, a[MAXN], pre[MAXN];

int find(int x) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    (x - mid + 1) * a[x] - (pre[x] - pre[mid - 1]) > m ? l = mid : r = mid - 1;
  }
  return l;
}

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> a[i++]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  int ans = 0;
  for (int r = 1; r <= n; r++) ans = max(ans, r - find(r));
  cout << ans;
  return 0;
}
