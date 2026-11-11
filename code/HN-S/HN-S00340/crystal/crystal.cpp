#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], sum[N], ans;

signed main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for(int i = 1; i <= n; i++){
    int l = 1, r = i, id = 0;
    while(l <= r){ int mid = (l + r) >> 1;
      (a[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m ? r = mid - 1, id = mid : l = mid + 1);
    }
    ans = max(ans, i - id + 1);
  }
  cout << ans;
  return 0;
}
