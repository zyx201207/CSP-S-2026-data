#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 5e5 + 5;

int n, a[MAXN];
ll s[MAXN], m;

int main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int l = 1, r = i;
    while(l < r){
      int mid = (l + r) >> 1;
      1ll * (i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m ? r = mid : l = mid + 1;
    }
    ans = max(ans, i - l + 1);
  }
  cout << ans;
  return 0;
}