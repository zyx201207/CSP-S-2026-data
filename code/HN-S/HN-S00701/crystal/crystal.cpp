#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll n, m, a[N], ans;
int main(){
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for(int i = 1;i <= n;i++){
    ll k = 0, sum = 0;
    for(int j = 1;j <= n;j++){
      if(a[j] <= a[i] && k + a[i] - a[j] <= m){
        k += a[i] - a[j];
        sum++;
      }
    }
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}
/**
qwq这就是提高组吗吓哭了
**/
