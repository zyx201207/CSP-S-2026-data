#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

int n, mx;
long long m, a[MAXN], sum[MAXN];

int BS(int p){
  int l = 1, r = p;
  while(l < r){
    int mid = (l + r) >> 1;
    if(1ll * (p - mid) * a[p] - (sum[p - 1] - sum[mid - 1]) <= m) r = mid;
    else l = mid + 1; 
  }
  return l;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for(int i = 1; i <= n; i++){
    int p = BS(i);
    // cout << i << ' ' << p << '\n';
    mx = max(mx, i - p + 1);
  }
  cout << mx;
  return 0;
}