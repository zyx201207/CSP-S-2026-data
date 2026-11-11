#include <iostream> 

using namespace std;
using ll = long long; 

void file () {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
}

const int kN = 2e6 + 5; 

int n;
ll d, a[kN]; 
int pre[kN], nxt[kN]; 
ll f[kN], g[kN], p[kN], q[kN]; 

void fakemain () {
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; 
  }
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j < n && a[j + 1] - a[i] <= d) ++j;
    nxt[i] = j; 
  }
  for (int i = n, j = n; i; --i) {
    while (j > 1 && a[i] - a[j - 1] <= d) --j;
    pre[i] = j; 
  }
  for (int i = 1; i <= n; ++i)
    f[i] = g[i] = 1, p[i] = q[i] = 0; 
  for (int i = 1; i <= n; ++i) {
    int j = nxt[i];
    if (j != i)
      f[j] += (i == pre[j] ? f[i] : 1);
  }
  for (int i = n; i; --i) {
    int j = pre[i];
    if (j != i)
      g[j] += (i == nxt[j] ? g[i] : 1);
  }
  ll ans = 0; 
  for (int i = 1; i <= n; ++i) {
    int x = nxt[i] - 1;
    if (i < x) p[x] += (pre[x] == i ? f[i] : 1);
    x = pre[i];
    if (i > x + 1) q[x] += (nxt[x + 1] == i ? g[i] : 1);
  }
  for (int x = 1; x < n; ++x)
    ans += p[x] * q[x];
  cout << ans << '\n';
}

int main () {
  file();
  cin.tie(0)->sync_with_stdio(0);
  int _, t;
  cin >> _ >> t;
  while (t--) fakemain();
  return 0; 
}