#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int a[N];
ll num[N], n, m;

int Solve(int i){
  int x = a[i], l = 1, r = i;
  while(l < r){
    int mid = (l + r) >> 1;
    ll v = num[mid] - num[i], p = i - mid;
    if(p * a[i] - v <= m){
      r = mid;
    }
    else{
      l = mid + 1;
    }
  }
  return l;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for(int i = n; i >= 1; i--){
    num[i] = num[i + 1] + a[i];
  }
  int maxx = 0;
  for(int i = 1; i <= n; i++){
    maxx = max(maxx, i - Solve(i) + 1);
  }
  cout << maxx;
  return 0;
}
