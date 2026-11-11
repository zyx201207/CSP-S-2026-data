#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;

int c, t, n;
long long d, a[MAXN], d1[MAXN], d2[MAXN];
bool f[MAXN];

int BS(int x){
  int l = x, r = n;
  while(l < r){
    int mid = (l + r + 1) >> 1;
    if(a[mid] - a[x] <= d) l = mid;
    else r = mid - 1;
  }
  return l;
}

int BS1(int x){
  int l = 1, r = x;
  while(l < r){
    int mid = (l + r) >> 1;
    if(a[x] - a[mid] <= d) r = mid;
    else l = mid + 1;
  }
  return l;
}

int BS2(int l, int r, int p){
  while(l < r){
    int mid = (l + r) >> 1;
    if(p - d2[mid] <= 1) r = mid;
    else l = mid + 1;
  }
  return l;
}

int BS3(int l, int r, int p){
  while(l < r){
    int mid = (l + r) >> 1;
    if(p == d2[mid]) r = mid;
    else l = mid + 1;
  }
  return l;
}

void Solve(){
  cin >> n >> d;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    d1[i] = BS(i), d2[i] = BS1(i);
    f[i] = 0;
    // cout << i << ' ' << d1[i] << ' ' << d2[i] << '\n';
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) f[j] = 0;
    f[d1[i]] = f[d1[i] - 1] = 1; 
    for(int j = d1[i]; j <= n; j = d1[j]){ // 向右跳
      if(j == d1[j]) break;
      int to = d1[j];
      int p1 = (j - d2[to] > 1 ? 0 : BS2(j + 1, to, j)), p2 = (j != d2[to] ? 0 : BS3(j + 1, to, j));
      
      // cout << i << ' ' << j << ' ' << p1 << ' ' << p2 << '\n';
      
      if(!p1) break;
      if(!p2){
        f[to] = 0;
        if(to - 1 != j) f[to - 1] = 0;
        if(f[j - 1]) ans += to - p1 + 1;
        else break;
      } else {
        f[to] = f[j];
        if(to - 1 != j) f[to - 1] = (d2[to - 1] == j ? f[j] : 0);
        if(!f[j]) ans += to - p2 + 1;
        if(f[j - 1]) ans += p2 - p1;
      }
      // cout << ans << '\n';
    }
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  cin >> c >> t;
  while(t--){
    Solve();
  }
  return 0;
}
/*
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/