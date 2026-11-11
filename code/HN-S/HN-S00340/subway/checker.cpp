#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

signed main(){
  freopen("subway.out", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int fl = 0;
  for(int i = 1, x; i <= n; i++){
    cin >> x, fl |= (a[i] != x);
  }
  cout << (!fl ? "YES" : "NO");
  return 0;
}
