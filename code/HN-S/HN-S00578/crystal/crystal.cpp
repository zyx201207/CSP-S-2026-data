#include <bits/stdc++.h>
using namespace std;

void File(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
}

const int kN = 5e5 + 7;
using ll = long long;
int n;
ll a[kN], s[kN], m;
signed main(){
  File();
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int mx = 0;
  for(int i = 1; i <= n; i++){
    int l = 1, r = i, mid, p = i;
    while(l <= r){
      mid = l + r >> 1;
      ll v = s[i] - s[mid - 1];
      if(1ll * (i - mid + 1) * a[i] - v <= m) r = mid - 1, p = mid;
      else l = mid + 1;
    }
    mx = max(mx, i - p + 1);
  }
  cout << mx << '\n';
  return 0;
}