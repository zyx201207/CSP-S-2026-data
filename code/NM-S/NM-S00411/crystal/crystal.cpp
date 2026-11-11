#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
 int n, m, a[N], b[N], op = 0, cnt = 0;
 cin >> n >> m;
 for (int i = 1; i <= n; i ++){
    cin >> a[i];
 }
 for (int i = 1; i <= n; i ++){
    b[i] = abs(a[i + 1] - a[i]);
 }
 for (int i = 1; i < n; i ++){
        op += b[i];
        if (op > m){
          break;
       }
       cnt ++;
 }
  cout << cnt + 1;
return 0;
}
