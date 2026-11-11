#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
  int a[N];
  long long n, m, idx = 0, op = -1;
  cin >> n >> m;
  for (int i = 1; i <= n; i ++){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= m; i ++){
      for (int j = 1; j <= m; j ++){
         if (i != j) idx = a[i] & a[j];
         else continue;
         if (idx > op) op = idx;
      }
    }
 cout << op;
return 0;
}
