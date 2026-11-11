#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, ans;
long long a[N], m, pre[N];

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
  for(int i = 1; i <= n; i++){
    pre[i] = pre[i - 1] + a[i];
  }
  for(int i = 1; i <= n; i++){
    int left = 1, right = i;
    while(left < right){
      int mid = (left + right) >> 1;
      if(m >= a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1])){
        right = mid;
      }else left = mid + 1;
    }
    ans = max(i - left + 1, ans);
  }
  cout << ans;
  return 0;
}
