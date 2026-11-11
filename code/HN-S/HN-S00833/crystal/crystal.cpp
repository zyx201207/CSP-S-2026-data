#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
using ll = long long;

ll n, m, a[N], b[N];

bool cmp(ll x, ll y){
  return x > y;
}

ll js(ll i){
  ll l = i, r = n, mid, ans = i;
  while(l <= r){
    mid = (l + r) / 2;
    if((mid - i + 1) * a[i] - (b[mid] - b[i - 1]) <= m){
      l = mid + 1;
      ans = max(ans, mid);
    }else{
      r = mid - 1;
    }
  }
  return ans - i + 1;
}

int main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= n; i++){
    b[i] = b[i - 1] + a[i];
  }
  ll ans = 1;
  for(int i = 1; i < n; i++){
    ans = max(ans, js(i));
  }
  cout << ans;
  return 0;
}
