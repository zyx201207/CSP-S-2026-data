#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 5e5 + 1;

int n, ans;
ll m, a[MAXN], sum[MAXN];

inline int F(int p){
  int l = 1, r = p;
  while(l < r){
    int mid = (l + r) >> 1;
    if((p - mid + 1) * a[p] - (sum[p] - sum[mid - 1]) <= m){
      r = mid;
    }else{
      l = mid + 1;
    }
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
  sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; i++){
    sum[i] = sum[i - 1] + a[i];
    ans = max(ans, i - F(i) + 1);
  }
  cout << ans;
  return 0;
}
