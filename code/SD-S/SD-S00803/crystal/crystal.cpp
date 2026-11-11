#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 5e5 + 7;
int n, m;
int a[N];
int s[N];
signed main() {
//  system("fc crystal.out crystal.ans");
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  } 
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++ i) {
    s[i] = s[i - 1] + a[i];
  }
  int l = 1, r, ans = 0;
  for (r = 1; r <= n; ++ r) {
    while (l <= r && s[r] - s[l - 1] + m < (r - l + 1) * a[r]) {
      ++ l;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << endl;
  return 0;
} 
