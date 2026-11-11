#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int kN = 2e6 + 5;
int n; ll d;
ll x[kN], sum[kN], sum2[kN];
int nxt[kN], up[kN];

ll Calc(int l, int r) {
  if(l == r) return 0;
  for(int i = r, j = r; i >= l; i--) {
    while(x[j] - x[i] > d) j--;
    nxt[i] = j;
  }
  up[r] = r;
  for(int i = r; i >= l; i--) {
    int f = nxt[i];
    if(nxt[f - 1] == nxt[f]) up[i] = i;
    else up[i] = up[f];
    sum[i] = sum[f];
    int x = nxt[i], y = nxt[x];
    if(nxt[x - 1] < y - 1) sum[i] += nxt[y - 1] - nxt[y - 2];
    sum2[i] = sum2[f] + nxt[i] - nxt[i - 1];
  }
  ll ans = 0;
  for(int i = l; i <= r; i++) {
    int p = up[i];
    if((nxt[nxt[p] - 2] < nxt[nxt[p]]) && ((p == i) || (nxt[p - 1] < nxt[p] - 1))) {
      int q = up[nxt[p]];
      ans += sum2[nxt[nxt[p]]] - sum2[nxt[nxt[q]]];
    }
    ans += sum[i] - sum[p];
    if(nxt[i] != n) {
      int l = max(nxt[nxt[i] - 2] + 1, nxt[i] + 1);
      int r = nxt[nxt[i] - 1];
      if(l <= r) ans += r - l + 1;
    }
  }
  return ans;
}

void Solve() {
  cin >> n >> d;
  for(int i = 0; i <= n + 2; i++) {
    x[i] = sum[i] = sum2[i] = nxt[i] = up[i] = 0;
  }
  for(int i = 1; i <= n; i++) cin >> x[i];
  ll ans = 0;
  for(int l = 1, r; l <= n; l = r + 1) {
    for(r = l; (r < n) && (x[r + 1] - x[r] <= d); r++) ;
    ans += Calc(l, r);
  }
  cout << ans << "\n";
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  int sid, t;
  cin >> sid >> t;
  while(t--) Solve();
  return 0;
}