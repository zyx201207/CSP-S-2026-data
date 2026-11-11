#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool aa;
const ll kM = 1e6 + 5;
ll n, m, a[kM], s[kM];
bool bb;
bool check(ll x){
  for(int i = x; i <= n; i++){
    if(i * a[i] - (s[i] - s[i - x]) <= m) return 1;
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n;i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++){
    s[i] = s[i - 1] + a[i];
  }
  ll sum = 0, l = 1, r = n;
  while(l < r){
    ll mid = (l + r + 1) >> 1;
    if(check(mid)) l = mid;
    else r = mid - 1;
  }
  cout << l;
  return 0;
}